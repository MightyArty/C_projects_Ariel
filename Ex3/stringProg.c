
#include <stdio.h>
#define TXT 1024
#define WORD 30




int G_HELP(char *w,int wLen) {
    int total = 0;
    int i = 0;
    int a = 0;
    for (i = 0; i < wLen; i++ , w++) {
        a = (int) *w;
        if (a >= 65 && a <= 90) {
            total += (a - 64);
        } else if (a >= 97 && a <= 122) {
            total += (a - 96);
        }
    }
    return total;
}

void G(char *w, char *t , int wLen, int tLen) {
    char ans[TXT];
    int  a=0 , b= 0 ,indexAns = 0;
    int val = G_HELP(w, wLen);
    char *end = t+tLen;

    for(int i =0 ;i<TXT;i++) ans[i] = '\0';
    for (char *i = (char *) t; *i!=*end; i++) {

        int total = 0;
        for (char *j = (char *) i; *j!=*end ; ++j) {

            a = (int) *j;
            if (a >= 65 && a <= 90) {
                total += (a - 64);
            } else if (a >= 97 && a <= 122) {
                total += (a - 96);
            }


            if(total>val) break;

            else if(total == val) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;

                int lett1 = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int lett2 = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));

                if(lett1 && lett2){
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while (start <= end) {
                        ans[indexAns++] =  *start++;
                    }
                    break;
                }
                else if(!lett1 && lett2){
                    while((*start < 65 || (*start > 90 && *start < 97) || *start > 122)){start++; i++;}
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while(start<=end)
                    {
                            ans[indexAns++] = *start++;
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}

void A(char* w,char* t,int wLen,int tLen){
    int a=0;
    int b=0;
    int indexAns =0;
    char ans[TXT];
    char *end = t + tLen;
    int val = G_HELP(w,wLen);
    for(int i =0 ;i<TXT;i++) ans[i] = '\0';
    for (char *i = (char *) t; *i!=*end; i++) {

        int sum = 0;
        for (char *j = (char *) i; *j!=*end ; ++j) {

            a = (int) *j;
            if (a >= 65 && a <= 90) {
                sum += (a - 64);
            } else if (a >= 97 && a <= 122) {
                sum += (a - 96);
            }

            if(sum>val) break;
            else if(sum == val) {
                char *start = (char *) i , *end = (char *) j;
                a = (int)*start;
                b = (int)*end;
                int lett1 = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int lett2 = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));
                if (!A_HELP((char *) start, (char *) end, (char *) w, wLen)) break;

                if(lett1 && lett2){
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while (start <= end) {
                        ans[indexAns++] =  *start++;
                    }
                    break;
                }
                else if(!lett1 && lett2){
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while(start<=end)
                    {
                        if((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122)){
                            ans[indexAns++] = *start++;
                        }
                        else {
                            start++;
                            i++;
                            lett1 = ((*start >= 65 && *start <= 90) || (*start >= 97 && *start <= 122));
                        }
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}
        
int A_HELP(char *s,char* e,char* w,int wLen){
    int src[26] = {0}, temp[26] = {0}, c = 0;
    if ((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122)) {
        while (s < e + 1) {
            if ((*s >= 97 && *s <= 122)){
                temp[*s - 'a']++;
                s++;
            }else if((*s >= 65 && *s <= 90)){
                temp[*s - 'A']++;
                s++;
            }
            else return 0;
        }
    }else{
        while((*s < 65 || (*s > 90 && *s < 97) || *s > 122)){s++;}
        while (s < e + 1) {
            if ((*s >= 97 && *s <= 122)){
                temp[*s - 'a']++;
                s++;
            }else if((*s >= 65 && *s <= 90)){
                temp[*s - 'A']++;
                s++;
            }
            else return 0;
        }
    }
    for (int i = 0; i < wLen; ++i) {
        if((*w >= 97 && *w <= 122)) {
            src[*w - 'a']++;
            w++;
        }else if((*w >= 65 && *w <= 90)) {
            src[*w - 'A']++;
            w++;
        }
        else return 0;
    }

    for (c = 0; c < 26 ; ++c) {
        if(src[c]!= temp[c]) return 0;
    }
    return 1;
}


int AB_HELP(char *s , char *e , char *w , int wLen){
    int u = 'Z' + 'A';
    int l = 'z' + 'a';
    char *pointerA  = (char *) s;
    char *pointerB  = (char *) e;
    char *pointerC = (char *)w;
    char *pointerD = (char *)w + wLen - 1 ;

    int temp1 = (int) *pointerA;
    int temp2 = (int) *pointerB;
    temp1 = (temp1 >= 65 && temp1 <= 90) ? u - temp1 : (temp1 >= 97 && temp1 <= 122) ? l - temp1 : 0;
    temp2 = (temp2 >= 65 && temp2 <= 90) ? u - temp2 : (temp2 >= 97 && temp2 <= 122) ? l - temp2 : 0;


    if(temp1 == *pointerC && temp2 == *pointerD)
    {
        for( ;pointerA!=pointerB ; pointerC++ , pointerA++)
        {
            temp1 = (int) *pointerA;
            temp1 = (temp1 >= 65 && temp1 <= 90) ? u - temp1 : (temp1 >= 97 && temp1 <= 122) ? l - temp1 : 0;
            if(*pointerC != temp1) return 0;

        }
        return 1;
    }
    else if(temp2 == *pointerC && temp1 == *pointerD)
    {
        for( ;pointerA!=pointerB ; pointerC++ , pointerB--)
        {
            temp2 = (int) *pointerB;
            temp2 = (temp2 >= 65 && temp2 <= 90) ? u - temp2 : (temp2 >= 97 && temp2 <= 122) ? l - temp2 : 0;
            if(*pointerC != temp2) return 0;
        }


        return 1;
    }

    return 0;
}

void AB(char *w, char *t , int wLen, int tLen) {
    char ans[TXT];
    int a=0;
    int b= 0; 
    int indexAns = 0;
    int val = G_HELP(w, wLen);
    char *end = t+tLen;
    for(int i =0 ;i<TXT;i++) ans[i] = '\0';
    int l = 'z' + 'a';
    int u = 'Z' + 'A';
    for (char *i = (char *) t; *i!=*end; i++) {
        int sumComp = 0;
        for (char *j = (char *) i; *j!=*end ; ++j){

            
            a = (int) *j;
            if (a >= 65 && a <= 90) {
                a = u - a;
                sumComp += (a - 64);
            
            } else if (a >= 97 && a <= 122) {
                a = l - a;
                sumComp += (a - 96);

            }
            if(sumComp>val) break;
            else if(sumComp == val) {
                char *s = (char *) i , *end = (char *) j;
                a = (int)*s;
                b = (int)*end;
                int lett1 = ((a >= 65 && a <= 90) || (a >= 97 && a <= 122));
                int lett2 = ((b >= 65 && b <= 90) || (b >= 97 && b <= 122));

                if(lett1 && lett2){
                    if(!AB_HELP((char *) s, (char *) end, (char *) w, wLen)) break;
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while (s <= end) {
                        ans[indexAns++] =  *s++;
                    }
                    break;
                }
                else if(!lett1 && lett2){
                    if(indexAns!=0){
                        ans[indexAns++] = '~';
                    }
                    while(s<=end)
                    {
                        lett1 = ((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122));
                        if(lett1) if(!AB_HELP((char *) s, (char *) end, (char *) w, wLen)) break;

                        if((*s >= 65 && *s <= 90) || (*s >= 97 && *s <= 122)){
                            ans[indexAns++] = *s++;
                        }
                        else {
                            s++;
                            i++;
                        }
                    }
                    break;
                }
            }
        }

    }
    printf("%s",ans);

}
