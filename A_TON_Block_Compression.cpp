#include <bits/stdc++.h>
#include <lz4.h>
using namespace std;
static const string base64s=
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

inline bool Ok(unsigned char c)
{
    return (isalnum(c) || (c=='+') || (c=='/'));
}
string base64s_encode(const vector<uint8_t>& TotalB)
{
    string ret;
    int i=0,j=0;
    uint32_t A,B,C;
    uint32_t Trip;
    size_t Inlen=TotalB.size();
    size_t pos=0;
    while(Inlen--)
    {
        A=TotalB[pos++];
        B=(Inlen-->0)?TotalB[pos++]:0;
        C=(Inlen-->0)?TotalB[pos++]:0;
        Trip=(A<<16)+(B<<8)+C;
        ret+=base64s[(Trip>>18)&0x3F];
        ret+=base64s[(Trip>>12)&0x3F];
        ret+=(Inlen+1>0)?base64s[(Trip>>6)&0x3F]:'=';
        ret+=(Inlen+1>1)?base64s[Trip&0x3F]:'=';
    }
    size_t mod=TotalB.size()%3;
    if(mod>0)
    {
        ret[ret.size()-1]='=';
        if(mod==1)
        {
            ret[ret.size()-2]='=';
        }
    }

    return ret;
}
vector<uint8_t> base64s_decode(const string& EncodeS)
{
    size_t Inlen=EncodeS.size();
    size_t i=0,j=0;
    uint32_t Sa,Sb,Sc,Sd;
    uint32_t Trip;
    vector<uint8_t>CodeD;
    while(i<Inlen)
    {
        Sa=EncodeS[i]=='='?0&i++:base64s.find(EncodeS[i++]);
        Sb=EncodeS[i]=='='?0&i++:base64s.find(EncodeS[i++]);
        Sc=EncodeS[i]=='='?0&i++:base64s.find(EncodeS[i++]);
        Sd=EncodeS[i]=='='?0&i++:base64s.find(EncodeS[i++]);
        Trip=(Sa<<18)+(Sb<<12)+(Sc<<6)+Sd;
        if(EncodeS[i-2]!='=')CodeD.push_back((Trip>>16)&0xFF);
        if(EncodeS[i-1]!='=')CodeD.push_back((Trip>>8)&0xFF);
        if(EncodeS[i]!='='&&i<=Inlen)CodeD.push_back(Trip&0xFF);
    }
    return CodeD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string M;
    getline(cin,M);
    string B64i;
    getline(cin,B64i);
    vector<uint8_t>DataIp=base64s_decode(B64i);
    if(M=="compress")
    {
        int Mxi=LZ4_compressBound(DataIp.size());
        vector<char>CmpD(Mxi);
        
        int CmpSza=LZ4_compress_default(
            reinterpret_cast<const char*>(DataIp.data()),
            CmpD.data(),
            DataIp.size(),
            Mxi
        );
        if(CmpSza<=0)
        {
            cerr<<"LZ4 compression failed\n";
            return 1;
        }
        CmpD.resize(CmpSza);
        vector<uint8_t>compB(CmpD.begin(),CmpD.end());
        string B64Ans=base64s_encode(compB);
        cout<<B64Ans<<endl;   
    }
    else if(M=="decompress")
    {
        size_t Osza=4*1024*1024;
        vector<char> Ch(Osza);
        int Sza=LZ4_decompress_safe(
            reinterpret_cast<const char*>(DataIp.data()),
            Ch.data(),
            DataIp.size(),
            Osza
        );
        if(Sza<0)
        {
            cerr<<"LZ4 decompression failed\n";
            return 1;
        }
        Ch.resize(Sza);
        vector<uint8_t>UniCh(Ch.begin(),Ch.end());
        string b64Op=base64s_encode(UniCh);
        cout<<b64Op<<endl;
    }
    else
    {
        cerr<<"Invalid M: "<<M<<endl;
        return 1;
    }
    return 0;
}