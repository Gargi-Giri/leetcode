class Solution {
public:
    vector<int> f(int n,int firstPlayer,int secondPlayer){
        /* base case : when the two players are at the same distance from their sides ,like first - last, or second - secondLast ,etc
        */
       if(firstPlayer+secondPlayer==n-1)return {1,1};

       int nn=n/2;
       int ansmi=INT_MAX,ansmx=INT_MIN;
    // Generating subsets
       for(int nmask=0;nmask<(1<<nn);nmask++){
            //tmask stores all the players that will go for next round. I need this because nmask only has the first half of players
            int tmask=nmask;
            // If n is odd then middle player is always included
            if(n%2)tmask|=(1<<nn);
            for(int i=0;i<nn;i++){
                // only if this player of first half is absent we include its opponent from second half
                if((nmask & (1<<i))==0){
                    tmask+=(1<<(n-1-i));
                }
            }
        // Check the criteria that both of our players are included in the set. because other players can't defeat them
            if((tmask & (1<<firstPlayer))==0 || (tmask & (1<<secondPlayer))==0)continue;
            //compress
            /*
            This compression is optional but it makes genrating 
            the subsets easy
            So, if firstPlayer was 2 and we have removed the two players before him , now firstPlayer is 0 (we consider 0-indexed) and same holds for secondPlayer.
            */
            int cnt=-1;
            int nf=-1,ns=-1;
            for(int k=0;k<n;k++){
                if((tmask & (1<<k))){
                    cnt++;
                    if(k==firstPlayer)nf=cnt;
                    else if(k==secondPlayer)ns=cnt;
                }
            }
            //Recurse with this subset
            vector<int>rec=f((n+1)/2,nf,ns);
            // calculate your answer
            ansmi=min(ansmi,1+rec[0]);
            ansmx=max(ansmx,1+rec[1]);
       }
       return {ansmi,ansmx}; // And here you go :)
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        //To make them zero indexed
        firstPlayer--;
        secondPlayer--;
       return f(n,firstPlayer,secondPlayer); 
    }
};
