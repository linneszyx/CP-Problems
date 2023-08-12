int nextOneForSure(int x, int y)
{
    if (y == 2)
        return 2;
    double prob = 1.0;
    int xi = 0;
    while (prob > 1e-6)
    {
        xi++;
        prob *= (1 - x / 100.0);
        if (xi >= y - 1)
        {
            return xi + 1;
        }
    }
    return y;
}
