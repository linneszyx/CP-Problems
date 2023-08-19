
int coinGame(int x, int y)
{
    if (x == y)
        return 0;
    if (x > y)
        return 1;
    return coinGame(x + 1, y) + 1;
}
