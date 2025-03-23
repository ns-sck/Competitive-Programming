vector<int> spf(MAX);
vector<int> prs;

for (int i = 2; i < MAX; ++i) {
	if (spf[i] == 0) {
		spf[i] = i;
		prs.push_back(i);
	}
	for (int j = 0; i * prs[j] < MAX; ++j) {
		spf[i * prs[j]] = prs[j];
		if (prs[j] == spf[i]) {
			break;
		}
	}
}