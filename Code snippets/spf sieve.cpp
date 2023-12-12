int spf[N+1];
void precompute(){
    for(int i = 2; i <=N; i+=2)
        spf[i] = 2;
    for(int i = 3; i*i <=N; i+=2){
        if(spf[i]==0){
            spf[i] = i;
            for(int j = i*i; j<=N; j+=i){
                if(spf[j]==0)
                    spf[j]=i;
            }
        }
    }
    for(int i = 2; i <=N; i++){
        if(!spf[i])
            spf[i]=i;
    }
}