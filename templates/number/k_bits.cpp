for (int msk = (1 << K) - 1; msk < (1 << N); ) {
    if (!msk) break;
    int x = msk & -msk, y = msk + x;
    msk = (msk & ~y) / x >> 1 | y;
}