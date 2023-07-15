#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int oclitMoRong(int r0, int r1){
    int r[100],q[100],s[100],t[100];
    r[0]=r0;
    r[1]=r1;
    s[0]=1;t[0]=0;
    s[1]=0;t[1]=1;
    int i=0;
    while(true){
        q[i+1]=r[i]/r[i+1];
        r[i+2]=r[i]%r[i+1];
        if(i>1){
            s[i]=s[i-2]-q[i-1]*s[i-1];
            t[i]=t[i-2]-q[i-1]*t[i-1];
        }
        if(r[i+2]==0) break;
        i++;
    }
    i++;
    s[i]=s[i-2]-q[i-1]*s[i-1];
    t[i]=t[i-2]-q[i-1]*t[i-1];
    return t[i]>0?t[i]:t[i]+r0;
}
int detK(int k[2][2]){
    int det=k[0][0]*k[1][1]-k[0][1]*k[1][0];
    while(det<0){
        det+=26;
    }
    return det%26;
}
void khoaGiaiMa(int k[2][2]){
    int detK1 = oclitMoRong(26,detK(k));
    int pK[2][2] = {{k[1][1],-k[0][1]},{-k[1][0],k[0][0]}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            while(pK[i][j]<0) pK[i][j]+=26;
            pK[i][j]*=detK1;
            pK[i][j]%=26;
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout<<pK[i][j]<<" ";
        }
        cout<<endl;
    }
}
void tichMatrix(int p[2], int k[2][2], int c[2]){
    for(int i=0;i<2;i++){
        c[i]=0;
        for(int j=0;j<2;j++){
            c[i]+=p[j]*k[j][i];
        }
        c[i]%=26;
    }
}
string hill(string s, int k[2][2]){
    string res="";
    for(int i=0;i<s.size();i+=2){
        int p[2] = {s[i]-'A',s[i+1]-'A'};
        int c[2];
        tichMatrix(p,k,c);
        res+=(char)(c[0]+'A');
        res+=(char)(c[1]+'A');
    }
    return res;
}
int main(){
    int k[2][2];
    cout<<"Nhap ma tran khoa k:"<<endl;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin>>k[i][j];
        }
    }
    cout<<"Khoa giai ma la:"<<endl;
    khoaGiaiMa(k);
    string s1, s2;
    cout<<"Nhap xau ki tu 1: ";
    cin>>s1;
    cout<<"Nhap xau ki tu 2: ";
    cin>>s2;
    if(hill(s1,k)==s2){
        cout<<"Ban da nhap dung";
    }else{
        cout<<"Ban da nhap sai";
    }
}
