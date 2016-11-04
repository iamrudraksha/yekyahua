#include <bits/stdc++.h>
using namespace std;
int movex[8] = {1,2,2,1,-1,-2,-2,-1};
int movey[8] = {2,1,-1,-2,-2,-1,1,2};

int main()
{
//    cout<<"yahoo!"<<endl;
    int t;
    cin>>t;
//    cout<<"chalo chalein"<<endl;
    while(t--){
        int x,y,m;
        cin>>x>>y>>m;
        vector< vector< int > > G;
    //    cout<<"aa gaye"<<endl;
        for(int i=0;i<8;i++){
            vector<int> temp;
            for(int j=0;j<8;j++){
                int a;
                cin>>a;
                temp.push_back(a);
            }
            G.push_back(temp);
        }
       
        //cout<<"yahoo 2 !"<<endl;
        map<pair<pair<int,int>,int>>dist;
       
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(G[i][j]==1){
                    if(i+1<8 && j-1<8 && i+1>=0 && j-1>=0 && G[i+1][j-1]!=2)
                        G[i+1][j-1]=1;
                    if(i-1<8 && j-1<8 && i-1>=0 && j-1>=0 && G[i-1][j-1]!=2)
                        G[i-1][j-1]=1;
                }
            }
        }
       
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                dist(make_pair(i,j))=INT_MAX;
       
       
        //cout<<"ho gaya ye"<<endl;
       
        priority_queue< pair<int, pair< int,int > >, vector< pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > q;
       
        map< pair<int,int>, pair<int,int> > parent;
       
        //<<"ye bhi ho gaya"<<endl;
       
        //pair<int,int> src = make_pair(x,y);
        q.push(make_pair(0, make_pair(x,y)));
        dist[make_pair(x,y)]=0;
        parent[make_pair(x,y)]=make_pair(-1,-1);
        int newdist;
        pair<int,int> dest=make_pair(-2,-2);
       
        while(!q.empty()){
            pair<int, pair<int,int> > v = q.top();
            q.pop();
           
            if(G[v.second.first][v.second.second]==2){
                dest = v.second;
                break;
            }
               
            for(int i=0;i<8;i++){
                pair<int,int> temp;
                temp.first = v.second.first  + movex[i];
                temp.second= v.second.second + movey[i];
                newdist = dist[v.second] + 1;
                if(newdist<dist[temp] && temp.first>=0 && temp.second>=0 && temp.first<8 && temp.second<8 && G[temp.first][temp.second]!=1){
                    dist[temp]=dist[v.second] + 1;
                    parent[temp]=v.second;
                    q.push(make_pair(dist[temp],temp));
                }
            }
        }
           
        if(dest==make_pair(-2,-2)){
            cout<<"no solution"<<endl;
            continue;
        }
       
        stack<pair<int,int>> s;
        while(dest!=make_pair(-1,-1)){
            s.push(dest);
            dest=parent[dest];
        }
        if(m==0){
            cout<<dist[dest]<<endl;
            continue;
        }
        else{
            while(!s.empty()){
                pair<int,int> a;
                a=s.top();
                s.pop();
                cout<<a.first<<" "<<a.second<<endl;
            }
            cout<<"end"<<endl;
        }
           
       
       
    }
    return 0;
}