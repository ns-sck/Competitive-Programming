#include <bits/stdc++.h>

using namespace std;

using ll = long long int;

class SumSegmentTree {
   public:
    SumSegmentTree(ll in_n) {
        n = in_n;
        tree.resize(4 * n, 0);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(ll index, ll number) {
        update(0, 0, n - 1, index, number);
    }

   private:
    vector<ll> tree;
    ll n;
    inline ll L(ll i) {
        return 2 * i + 1;
    }
    inline ll R(ll i) {
        return 2 * i + 2;
    }

    void update(ll si, ll sl, ll sr, ll index, ll num) {
        if (index < sl || sr < index)
            return;
        if (sl == sr && sl == index) {
            tree[si] = num;
            return;
        }
        ll mid = (sl + sr) >> 1;
        update(L(si), sl, mid, index, num);
        update(R(si), mid + 1, sr, index, num);
        tree[si] = tree[L(si)] + tree[R(si)];
    }

    ll query(ll si, ll sl, ll sr, ll l, ll r) {
        if (r < sl || sr < l)
            return 0;
        if (l <= sl && sr <= r)
            return tree[si];
        ll mid = (sl + sr) >> 1;
        return query(L(si), sl, mid, l, r) + query(R(si), mid + 1, sr, l, r);
    }
};

class MaxSegmentTree {
   public:
    MaxSegmentTree(vector<ll>& nums) {
        n = nums.size();
        tree.resize(4 * n, 0);
        build(nums, 0, 0, n - 1);
    }

    ll findFirstGreaterNumbersIndex(ll num, ll l, ll r) {
        return findFirstGreaterNumbersIndex(0, 0, n - 1, l, r, num);
    }

    ll findLastGreaterNumbersIndex(ll num, ll l, ll r) {
        return findLastGreaterNumbersIndex(0, 0, n - 1, l, r, num);
    }

    void update(ll index, ll number) {
        update(0, 0, n - 1, index, number);
    }

    ll query(ll l, ll r) {
        return query(0, 0, n - 1, l, r);
    }

   private:
    vector<ll> tree;
    ll n;
    inline ll L(ll i) {
        return 2 * i + 1;
    }
    inline ll R(ll i) {
        return 2 * i + 2;
    }

    void build(vector<ll>& nums, ll si, ll l, ll r) {
        if (l == r) {
            tree[si] = nums[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(nums, L(si), l, mid);
        build(nums, R(si), mid + 1, r);
        tree[si] = max(tree[L(si)], tree[R(si)]);
    }

    void update(ll si, ll sl, ll sr, ll index, ll num) {
        if (index < sl || sr < index)
            return;
        if (sl == sr && sl == index) {
            tree[si] = num;
            return;
        }
        ll mid = (sl + sr) >> 1;
        update(L(si), sl, mid, index, num);
        update(R(si), mid + 1, sr, index, num);
        tree[si] = max(tree[L(si)], tree[R(si)]);
    }

    ll query(ll si, ll sl, ll sr, ll l, ll r) {
        if (r < sl || sr < l)
            return 0;
        if (l <= sl && sr <= r)
            return tree[si];
        ll mid = (sl + sr) >> 1;
        return max(query(L(si), sl, mid, l, r), query(R(si), mid + 1, sr, l, r));
    }

    ll findFirstGreaterNumbersIndex(ll si, ll sl, ll sr, ll l, ll r, ll num) {
        if (r < sl || sr < l)
            return -1;
        if (tree[si] <= num)
            return -1;
        if (sl == sr)
            return sl;
        ll mid = (sl + sr) >> 1;
        ll lAnswer = findFirstGreaterNumbersIndex(L(si), sl, mid, l, r, num);
        if (lAnswer != -1)
            return lAnswer;
        return findFirstGreaterNumbersIndex(R(si), mid + 1, sr, l, r, num);
    }

    ll findLastGreaterNumbersIndex(ll si, ll sl, ll sr, ll l, ll r, ll num) {
        if (r < sl || sr < l)
            return -1;
        if (tree[si] <= num)
            return -1;
        if (sl == sr)
            return sl;
        ll mid = (sl + sr) >> 1;
        ll rAnswer = findLastGreaterNumbersIndex(R(si), mid + 1, sr, l, r, num);
        if (rAnswer != -1)
            return rAnswer;
        return findLastGreaterNumbersIndex(L(si), sl, mid, l, r, num);
    }
};

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector<ll> numbers(n + 2);
    vector<pair<ll, ll>> numsWithIndexes(n + 2);
    for (ll i = 1; i <= n; i++) {
        cin >> numsWithIndexes[i].first;
        numsWithIndexes[i].second = i;
        numbers[i] = numsWithIndexes[i].first;
    }
    numsWithIndexes[0].first = 0;
    numsWithIndexes[n + 1].first = 0;
    numsWithIndexes[0].second = 0;
    numsWithIndexes[n + 1].second = n + 1;

    sort(numsWithIndexes.begin(), numsWithIndexes.end());

    MaxSegmentTree mst{numbers};
    SumSegmentTree sst{n + 2};
    SumSegmentTree filledSegmentTree{n + 2};  // holds 1 for updated, 0 for not updated

    auto originalNumbers = numbers;
    sort(numbers.begin(), numbers.end());  // for binary search

    ll q;
    cin >> q;
    vector<tuple<ll, ll, ll, ll>> queries(q);
    for (ll i = 0; i < q; i++) {
        ll l, r, m;
        cin >> l >> r >> m;
        queries[i] = {m, l, r, i};
    }

    sort(queries.begin(), queries.end());

    vector<ll> speedUpInc(n + 2);
    vector<ll> speedUpDec(n + 2);
    speedUpInc[0] = 0;
    for (ll i = 1; i <= n + 1; i++) {
        speedUpInc[i] = i;
        if (originalNumbers[i - 1] <= originalNumbers[i])
            speedUpInc[i] = speedUpInc[i - 1];
    }
    speedUpDec[n + 1] = n + 1;
    for (ll i = n; i >= 0; i--) {
        speedUpDec[i] = i;
        if (originalNumbers[i] >= originalNumbers[i + 1])
            speedUpDec[i] = speedUpDec[i + 1];
    }
    // for (ll i = 0; i < n + 2; i++)
    //     cout << speedUpInc[i] << ", ";
    // cout << "\n";
    // for (ll i = 0; i < n + 2; i++)
    //     cout << speedUpDec[i] << ", ";
    // cout << "\n";

    ll lastPushedIndex = -1;
    vector<ll> answers(q);
    for (ll i = 0; i < q; i++) {
        auto [m, l, r, queryIndex] = queries[i];
        // printf("Processing query (l: %lli, r: %lli, m: %lli, queryIndex: %lli)\n", l, r, m, queryIndex);

        // update segment trees
        ll pushUntil = upper_bound(numbers.begin(), numbers.end(), m) - numbers.begin();
        for (ll j = lastPushedIndex + 1; j < pushUntil; j++) {
            auto [number, index] = numsWithIndexes[j];
            // printf("Pushing numbers[%lli] = %lli\n", index, number);
            // mst.update(index, number);
            // mst_r.update(n + 1 - index, number);
            sst.update(index, number);
            filledSegmentTree.update(index, 1);
        }
        lastPushedIndex = pushUntil - 1;

        // increase ranges
        // while (l > 0 && originalNumbers[l] >= originalNumbers[l - 1])
        //     l--;
        // while (r < n && originalNumbers[r] >= originalNumbers[r + 1])
        //     r++;
        l = max(speedUpInc[l], 1ll);
        r = min(speedUpDec[r], n + 1);
        // cout << "Range: " << l << ", " << r << "\n";

        // printf("Extended Range | l: %lli, r: %lli\n", l, r);
        ll lBound = mst.findLastGreaterNumbersIndex(m, 0, l - 1);
        ll rBound = mst.findFirstGreaterNumbersIndex(m, r + 1, n + 1);
        lBound = lBound == -1 ? 1 : lBound;
        rBound = rBound == -1 ? n : rBound;
        // printf("lBound: %lli, rBound: %lli\n", lBound, rBound);

        ll filledCount = filledSegmentTree.query(lBound, rBound);
        ll sum = sst.query(lBound, rBound);

        answers[queryIndex] = filledCount * m - sum;
        // printf("Answer[%lli] = %lli\n", queryIndex, filledCount * m - sum);
    }

    for (auto ans : answers)
        cout << ans << "\n";

    return 0;
}