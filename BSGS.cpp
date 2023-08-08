```cpp
ll BSGS(ll a, ll b, ll p)
{
    a %= p;
    b %= p;
    if (!a && !b) return 1;
    if (!a && b) return -1;
    mp.clear();
    ll k = sqrt(p) + 1, r = 1;
    for (int i = 0; i < k; i++)
    {
        mp[r] = i;
        r = r * a % p;
    }
    r = qpow(a, p - 1 - k, p);
    for (int i = 0; i < k; i++)
    {
        if (mp.count(b)) return i * k + mp[b];
        b = b * r % p;
    }
    return -1;
}
```