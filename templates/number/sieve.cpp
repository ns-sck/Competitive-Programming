vector<int> spf(MAX);
vector<int> prs;

void sieve() {
	for (int i = 2; i < MAX; ++i) {
		if (spf[i]) {
			continue;
		}
		spf[i] = i;
		prs.emplace_back(i);
		for (int j = i * i; j < MAX; j += i) {
			if (!spf[j]) {
				spf[j] = i;
			}
		}
	}
}