ll phi(ll x) {
    ll ans = x;
    for(ll i = 2ll; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
				x /= i;
			}
            ans -= (ans / i);
        }
    }
    if (x > 1ll) {
		ans -= ans / x;
	}
    return ans;
}