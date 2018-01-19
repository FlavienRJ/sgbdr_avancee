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
    int r,i,n;
    int selectnb=0,fromnb=0,wherenb=0,unionnb=0,unionps=0,intersectnb=0,intersectps=0,insertnb=0,insertps=0,updatenb=0,updateps=0,deletenb=0,deleteps=0,commitnb=0,commitps=0;
    int selectps[2], fromps[2], whereps[2];
    RELATION r1, r2;
    regex_t reg;
    
    //LEXING
    r = regcomp(&reg, "SELECT", REG_NOSUB|REG_EXTENDED);
    for(i=1;i<argc;i++)
    {
        //filter(argv[i]);
        r = regcomp(&reg, "SELECT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            selectps[selectnb]=i;
            selectnb++;
            
        }
        r = regcomp(&reg, "FROM", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            fromps[fromnb]=i;
            fromnb++;
        }
        r = regcomp(&reg, "WHERE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            whereps[wherenb]=i;
            wherenb++;
        }
        r = regcomp(&reg, "UNION", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            unionps=i;
            unionnb++;
        }
        r = regcomp(&reg, "INTERSECT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            intersectps=i;
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
    
    printf("%i, %i, %i, %i, %i, %i\n",selectnb,fromnb,wherenb,selectps[0],fromps[0],whereps[0]);
    //PARSING
    
    if((selectnb==0)||(selectnb!=fromnb)||(selectnb!=(unionnb+1||intersectnb+1))||((unionnb==intersectnb)&&unionnb==1)/*||(!isdigit(*argv[fromps[0]+1]))*/)
    {
        printf("SQL request not coherent enough\n");
    }
    else
    {
        n=2;
        if(unionnb==1||intersectnb==1)n++;
        
        for(i=1;i<n;i++)
        {       
            if(selectnb==i)
            {
                if(wherenb==i&&(whereps[i-1]-fromps[i-1])==3)
                {
                    filter(argv[fromps[i-1]+1]);
                    filter(argv[fromps[i-1]+2]);
                    filter(argv[whereps[i-1]+1]);
                    filter(argv[whereps[i-1]+3]);
                    r2=OpJointure(stringtoRELATION(argv[fromps[i-1]+1],bdd),stringtoRELATION(argv[fromps[i-1]+2],bdd),atoi(argv[whereps[i-1]+1]),atoi(argv[whereps[i-1]+3]));
                }
                if(wherenb==1&&(whereps[i-1]-fromps[i-1])==2)
                {
                    filter(argv[fromps[i-1]+1]);
                    filter(argv[whereps[i-1]+1]);
                    filter(argv[whereps[i-1]+2]);//A enlever plus tard
                    filter(argv[whereps[i-1]+3]);
                    if(/*isdigit(*argv[whereps[i-1]+3])*/1)
                    {
                        
                        r2=OpRestrictionCST(stringtoRELATION(argv[fromps[i-1]+1],bdd),atoi(argv[whereps[i-1]+1]),atoi(argv[whereps[i-1]+2]),atoi(argv[whereps[i-1]+3]));
                    }
                    else
                    {
                        r2=OpRestrictionATT(stringtoRELATION(argv[fromps[i-1]+1],bdd),atoi(argv[whereps[i-1]+1]),atoi(argv[whereps[i-1]+2]),atoi(argv[whereps[i-1]+3]));
                    }
                }
                if(wherenb==0&&(argc-fromps[i-1])==3)
                {
                    filter(argv[fromps[i-1]+1]);
                    filter(argv[fromps[i-1]+2]);
                    r2=OpProduitCartesien(stringtoRELATION(argv[fromps[i-1]+1],bdd),stringtoRELATION(argv[fromps[i-1]+2],bdd));
                }
                /*if(wherenb==0&&(argc-fromps[i-1])==2)
                {
                    r2=OpProjection(stringtoRELATION(filter(argv[selectps[i-1]+1]),bdd),filter(argv[fromps[i-1]+1]));
                }*/
            }
            if(i=1)r1=r2;
        }
        
        if(unionnb==1)
        {
            r1=OpUnion(r1,r2);
        }
        if(intersectnb==1)
        {
            r1=OpInter(r1,r2);
        }
        
    }
    regfree(&reg);
    return r1;
}
