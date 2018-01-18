#include "parser.h"

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


RELATION parser(int argc, char **argv, BDD* bdd)
{
    int r,i,n;
    int selectnb=0,fromnb=0,wherenb=0,unionnb=0,unionps=0,intersectnb=0,intersectps=0;
    int selectps[2], fromps[2], whereps[2];
    RELATION r1, r2;
    regex_t reg;

    //LEXING
    r = regcomp(&reg, "SELECT", REG_NOSUB|REG_EXTENDED);
    for(i=1;i<argc;i++)
    {
        filter(argv[i]);
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
    }
    
    //printf("%i, %i, %i, %i, %i, %i\n",selectnb,fromnb,wherenb,selectps[0],fromps[0],whereps[0]);
    
    //PARSING
    
    if((selectnb==0)||(selectnb!=fromnb)||(selectnb!=(unionnb+1||intersectnb+1))||((unionnb==intersectnb)&&unionnb==1))
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
                    r2=OpJointure(argv[fromps[i-1]+1],argv[fromps[i-1]+2],argv[whereps[i-1]+1],argv[whereps[i-1]+3]);
                }
                if(wherenb==1&&(whereps[i-1]-fromps[i-1])==2)
                {
                    r2=OpRestriction(argv[fromps[i-1]+1],argv[whereps[i-1]+1],argv[whereps[i-1]+2],argv[whereps[i-1]+3]);
                }
                if(wherenb==0&&(argc-fromps[i-1])==3)
                {
                    r2=OpProduitCartesien(argv[fromps[i-1]+1],argv[fromps[i-1]+2]);
                }
                if(wherenb==0&&(argc-fromps[i-1])==2)
                {
                    r2=OpProjection(argv[selectps[i-1]+1],argv[fromps[i-1]+1]);
                }
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
