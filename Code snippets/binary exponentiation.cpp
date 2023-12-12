ll binexp(ll base, ll exp, ll M){
    if(exp==0)
        return 1;
    ll ret = binexp(base, exp/2, M);
    ret=((ret%M)*(ret%M))%M;
    if(exp&1)
        return ((ret%M)*(base%M))%M;
    return ret;
}

// iterative

ll binexp(ll base, ll exp, ll M) {
	base %= M;
	ll res = 1;
	while (exp > 0) {
		if (exp % 2 == 1) { res = res * base % M; }
		base = base * base % M;
		exp>>=1;
	}
	return res;
}