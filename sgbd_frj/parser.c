#include "parser.h"

//COMMIT INSERT DELETE UPDATE
//Rajouter chaque requête dans le journal
//Affiner la fonction de test

/** 
 * @brief Delete every character that is not a letter or a number
 * @note   
 * @param  src: The string to filter
 * @retval None
 */
void filterParser(char* src)
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

/** 
 * @brief Return a relation from a number
 * @note   
 * @param  s: The relation number
 * @param  bdd: The bdd structure
 * @retval 
 */
RELATION stR(char* s, BDD* bdd)
{
    return bdd->data[atoi(s)];
}

/** 
 * @brief Detect what kind of arguments there is and makes the related operations. Is a bit capricious still.
 * @note   
 * @param  argc: Regular argc
 * @param  **argv: Regular arv
 * @param  bdd: The bdd structure
 * @param  log: The log structure 
 * @retval 
 */
RELATION parser(int argc, char **argv, BDD* bdd, JOURNAL* log)
{
    int r,i,j,n;
    int selectnb=0,fromnb=0,wherenb=0,unionnb=0,unionps=0,intersectnb=0,insertnb=0,updatenb=0,deletenb=0,commitnb=0;
    RELATION r1, r2;
    OPERATION select[2], from[2], where[2];
    OPERATION unionop, intersect;
    regex_t reg;
    
    //LEXING
    for(i=1;i<argc;i++)
    {
        filterParser(argv[i]);
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
            //insertps=i;
            insertnb++;
        }
        r = regcomp(&reg, "UPDATE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            //updateps=i;
            updatenb++;
        }
        r = regcomp(&reg, "DELETE", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            //deleteps=i;
            deletenb++;
        }
        r = regcomp(&reg, "COMMIT", REG_NOSUB|REG_EXTENDED);
        if (regexec(&reg, argv[i], 1, NULL, 0) != REG_NOMATCH)
        {
            //commitps=i;
            commitnb++;
        }
    }
    
    //PARSING
    
    if((selectnb==0)||(selectnb!=fromnb)||(selectnb!=(unionnb+1||intersectnb+1))||((unionnb==intersectnb)&&unionnb==1)/*||(!isdigit(*argv[fromps[0]+1]))*/)
    {
        printf("SQL request not coherent enough\n");
    }
    else
    {
        //Writing in the log journal
        //for(i=1;i<argc;i++);
        //{
            //Problème avec logNewCommand, commenté pour le momoent
            //logNewCommand(log,argv[i]);
        //}
        
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
            n=from[i].argc;
            from[i].argc=where[i].argc-from[i].argc-1;
            if(from[i].argc<=0)
            {
                from[i].argc=argc-n-1;
                from[i].argv=(char**)malloc(sizeof(char**)*from[i].argc);
                for(j=0;j<from[i].argc;j++)
                {
                    from[i].argv[j]=argv[argc-from[i].argc+j];
                }
            }
            else
            {
                from[i].argv=(char**)malloc(sizeof(char**)*(from[i].argc));
                for(j=0;j<from[i].argc;j++)
                {
                    from[i].argv[j]=argv[where[i].argc-from[i].argc+j];
                }
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
                    r2=newRELATION((stR(from[i].argv[0],bdd).attsize + stR(from[i].argv[1],bdd).attsize - 1), (stR(from[i].argv[0],bdd).sizemax > stR(from[i].argv[1],bdd).sizemax) ? stR(from[i].argv[0],bdd).sizemax : stR(from[i].argv[1],bdd).sizemax);
                    r2=OpJointure(stR(from[i].argv[0],bdd),stR(from[i].argv[1],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[2]));
                }
                if(wherenb==1&&from[i].argc==1)
                {
                    if(isdigit(*where[i].argv[2]))
                    {
                        r2 = newRELATION(bdd->data[atoi(from[i].argv[0])].attsize, bdd->data[atoi(from[i].argv[0])].sizemax);
                        r2=OpRestrictionCST(stR(from[i].argv[0],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[1]),atoi(where[i].argv[2]));
                    }
                    else
                    {
                        r2 = newRELATION(bdd->data[atoi(from[i].argv[0])].attsize, bdd->data[atoi(from[i].argv[0])].sizemax);
                        r2=OpRestrictionCST(stR(from[i].argv[0],bdd),atoi(where[i].argv[0]),atoi(where[i].argv[1]),atoi(where[i].argv[2]));
                    }
                }
                if(wherenb==0&&from[i].argc==2)
                {
                    r2 = newRELATION((stR(from[i].argv[0],bdd).attsize+stR(from[i].argv[1],bdd).attsize),stR(from[i].argv[0],bdd).size*stR(from[i].argv[1],bdd).size);
                    r2=OpProduitCartesien(stR(from[i].argv[0],bdd),stR(from[i].argv[1],bdd));
                }
                if(wherenb==0&&from[i].argc==1)
                {
                    int* tab;
                    tab=(int*)malloc(sizeof(int*)*select[i].argc);
                    for(j=0;j<select[i].argc;j++)
                    {
                        tab[j]=atoi(select[i].argv[j]);
                    }
                    r2 = newRELATION(select[i].argc, stR(from[i].argv[0],bdd).sizemax);
                    r2=OpProjection(stR(from[i].argv[0],bdd),tab,select[i].argc);
                }
            }
            if(i==1)r1=r2;
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
    return r2;
}
