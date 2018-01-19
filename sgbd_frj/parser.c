#include "parser.h"

//COMMIT INSERT DELETE UPDATE
//Modifier l'appel à OpJointure
//Faire disjonction de cas OpRestriction
//Rajouter chaque requête dans le journal
//Affiner la fonction de test

void filter(char* src)
{
    int i=0;
    char* p;
    for (p = src; *p != '\0'; p++) {
        if (islower(*p) || isdigit(*p) || isupper(*p))
        {
            src[i]=*p;
            i++;
        }
        if(*p=='.')
        {
            i=0;
        }
    }
    src[i]='\0';
}

RELATION stringtoRELATION(char* s, BDD* bdd)
{
    int tmp;
    RELATION rtmp;
    tmp=atoi(s);
    rtmp=bdd->data[tmp];
    return rtmp;
}

RELATION parser(int argc, char **argv, BDD* bdd)
{
    int r,i,j,n;
    int selectnb=0,fromnb=0,wherenb=0,unionnb=0,unionps=0,intersectnb=0,intersectps=0,insertnb=0,insertps=0,updatenb=0,updateps=0,deletenb=0,deleteps=0,commitnb=0,commitps=0;
    //int selectps[2], fromps[2], whereps[2];
    RELATION r1, r2;
    OPERATION select[2], from[2], where[2];
    OPERATION unionop, intersect;
    regex_t reg;
    
    //LEXING
    r = regcomp(&reg, "SELECT", REG_NOSUB|REG_EXTENDED);
    for(i=1;i<argc;i++)
    {
        filter(argv[i]);
        r = regcomp(&reg, "SELECT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            select[selectnb].op=SELECT;
            select[selectnb].argc=i;
            selectnb++;
            
        }
        r = regcomp(&reg, "FROM", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            from[fromnb].op=FROM;
            from[fromnb].argc=i;
            fromnb++;
        }
        r = regcomp(&reg, "WHERE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            where[wherenb].op=WHERE;
            where[wherenb].argc=i;
            wherenb++;
        }
        r = regcomp(&reg, "UNION", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            unionop.op=UNION;
            unionop.argc=i;
            unionnb++;
        }
        r = regcomp(&reg, "INTERSECT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            intersect.op=INTERSECT;
            intersect.argc=i;
            intersectnb++;
        }
        r = regcomp(&reg, "INSERT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            insertps=i;
            insertnb++;
        }
        r = regcomp(&reg, "UPDATE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            updateps=i;
            updatenb++;
        }
        r = regcomp(&reg, "DELETE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            deleteps=i;
            deletenb++;
        }
        r = regcomp(&reg, "COMMIT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            commitps=i;
            commitnb++;
        }
    }
    
    //printf("%i, %i, %i, %i, %i, %i\n",selectnb,fromnb,wherenb,selectps[0],fromps[0],whereps[0]);
    //PARSING
    
    if((selectnb==0)||(selectnb!=fromnb)||(selectnb!=(unionnb+1||intersectnb+1))||((unionnb==intersectnb)&&unionnb==1)/*||(!isdigit(*argv[fromps[0]+1]))*/)
    {
        printf("SQL request not coherent enough\n");
    }
    else
    {
        //Initialize operators
        for(i=0;i<selectnb;i++)
        {
            select[i].argc=from[i].argc-select[i].argc-1;
            select[i].argv=(char**)malloc(sizeof(char**)*select[i].argc);
            for(j=0;j<select[i].argc;j++)
            {
                select[i].argv[j]=argv[from[i].argc-select[i].argc+j];
            }
        }
        for(i=0;i<fromnb;i++)
        {
            from[i].argc=where[i].argc-from[i].argc-1;
            from[i].argv=(char**)malloc(sizeof(char**)*from[i].argc);
            for(j=0;j<from[i].argc;j++)
            {
                from[i].argv[j]=argv[where[i].argc-from[i].argc+j];
            }
        }
        for(i=0;i<wherenb;i++)
        {
            n=where[i].argc;
            where[i].argc=3;
            where[i].argv=(char**)malloc(sizeof(char**)*where[i].argc);
            for(j=0;j<where[i].argc;j++)
            {
                where[i].argv[j]=argv[n+1+j];
            }
        }
        
        //Calling everything like it should
        n=2;
        if(unionnb==1||intersectnb==1)n++;
        
        for(i=0;i<n-1;i++)
        {       
            if(selectnb==i+1)
            {
                if(wherenb==i+1&&from[i].argc==2)
                {
                    r2=newRELATION((stringtoRELATION(from[i].argv[0],bdd).attsize + stringtoRELATION(from[i].argv[1],bdd).attsize - 1), (stringtoRELATION(from[i].argv[0],bdd).sizemax > stringtoRELATION(from[i].argv[1],bdd).sizemax) ? stringtoRELATION(from[i].argv[0],bdd).sizemax : stringtoRELATION(from[i].argv[1],bdd).sizemax);
                    r2=OpJointure(stringtoRELATION(from[i].argv[0],bdd),stringtoRELATION(from[i].argv[1],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[1]));
                }
                if(wherenb==1&&from[i].argc==1)
                {
                    if(/*isdigit(*argv[whereps[i-1]+3])*/1)
                    {
                        printf("%s,%i,%i,%i\n",from[i].argv[0],atoi(where[i].argv[0]),atoi(where[i].argv[1]),atoi(where[i].argv[2]));
                        r2 = newRELATION(stringtoRELATION(from[i].argv[0],bdd).attsize, stringtoRELATION(from[i].argv[0],bdd).sizemax);
                        r2=OpRestrictionCST(stringtoRELATION(from[i].argv[0],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[1]),atoi(where[i].argv[2]));
                    }
                    else
                    {
                        r2 = newRELATION(stringtoRELATION(from[i].argv[0],bdd).attsize, stringtoRELATION(from[i].argv[0],bdd).sizemax);
                        r2=OpRestrictionATT(stringtoRELATION(from[i].argv[0],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[1]),atoi(where[i].argv[2]));
                    }
                }
                if(wherenb==0&&from[i].argc==2)
                {
                    r2 = newRELATION((stringtoRELATION(from[i].argv[0],bdd).attsize+stringtoRELATION(from[i].argv[1],bdd).attsize),stringtoRELATION(from[i].argv[0],bdd).size*stringtoRELATION(from[i].argv[1],bdd).size);
                    r2=OpProduitCartesien(stringtoRELATION(from[i].argv[0],bdd),stringtoRELATION(from[i].argv[1],bdd));
                }
                if(wherenb==0&&from[i].argc==1)
                {
                    int* tab;
                    tab=(int*)malloc(sizeof(int*)*select[i].argc);
                    for(j=0;j<select[i].argc;i++)
                    {
                        tab[j]=atoi(select[i].argv[j]);
                    }
                    r2 = newRELATION(stringtoRELATION(from[i].argv[0],bdd).attsize, stringtoRELATION(from[i].argv[0],bdd).sizemax);
                    r2=OpProjection(stringtoRELATION(from[i].argv[0],bdd),tab,select[i].argc);
                }
            }
            if(i=1)r1=r2;
        }
        
        if(unionnb==1)
        {
            r1= newRELATION(r1.attsize,r1.sizemax + r2.sizemax);
            r1=OpUnion(r1,r2);
        }
        if(intersectnb==1)
        {
            r1 =  newRELATION(r1.attsize, r1.sizemax);
            r1=OpInter(r1,r2);
        }
        
    }
    regfree(&reg);
    return r1;
}
