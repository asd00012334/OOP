#include <bits/stdc++.h>

using namespace std;

vector<string> modeList={"cat","removetag","exit"};

int main(int argv, char* argc[]){
    fstream fin;
    if(argv<=1) return 0;
    fin.open(argc[1],ios::in);
    vector<string> buff(1000);
    for(int line=0;line<1000;line++){
        string ssBuf;
        stringstream ss;
        vector<string> cmd;
        getline(fin,ssBuf);
        if(ssBuf.size()==0){
            line--;
            continue;
        }
        ss.str(ssBuf);
        while(1){
            string temp;
            if(ss>>temp) cmd.push_back(temp);
            else break;
        }
        cout<<"%";
        for(int cnt=0;cnt<cmd.size();cnt++){
            cout<<" ";
            cout<<cmd[cnt];
        }
        cout<<endl;
        /**Validity Checking*/
        bool valid=false;
        for(int cnt=0;cnt<modeList.size();cnt++)
            if(cmd[0]==modeList[cnt]){
                valid=true;
                break;
            }
        if(!valid){
            cout<<"unknown command\n";
            line--;
            continue;
        }

        /**Loading*/
        if(cmd.size()>1){
            bool isFile=true;
            for(int cnt=0;cnt<modeList.size();cnt++)
                if(cmd[1]==modeList[cnt])
                    isFile=false;
            if(cmd[1]=="<"||cmd[1][0]=='|') isFile=false;
            if(isFile){
                fstream File;
                File.open(cmd[1],ios::in);
                while(1){
                    char temp=File.get();
                    if(temp==EOF) break;
                    buff[line].push_back(temp);
                }
                File.close();
            }
        }

        /**Processing*/
        if(cmd[0]=="removetag"){
            string rmtag="=+,.'\\\"!-;()";
            int form,latt;
            form=latt=0;
            for(;latt<buff[line].size();latt++){
                bool take=true;
                for(int cnt=0;cnt<rmtag.size();cnt++)
                    if(buff[line][latt]==rmtag[cnt]){
                        take=false;
                        break;
                    }
                if(take)
                    buff[line][form++]=buff[line][latt];
            }
            buff[line].resize(form);
        }
        else if(cmd[0]=="exit") break;

        /**Redirecting*/
        for(int para=1;para<cmd.size();para++){
            if(cmd[para][0]=='|'){
                buff[line+atoi(cmd[para].c_str()+1)]+=buff[line];
                buff[line].clear();
                break;
            }
            else if(cmd[para]==">"){
                fstream fileOut;
                fileOut.open(cmd[para+1],ios::out);
                fileOut<<buff[line];
                fileOut.close();
                buff[line].clear();
                break;
            }
        }

        /**Outputting*/
        if(cmd[0]=="cat")
            cout<<buff[line];
    }
    fin.close();
}
