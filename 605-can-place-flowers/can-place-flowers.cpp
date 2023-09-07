class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size(); // get the size of the flowerbed
        int counting = 0; // initialize a counting variable to keep track of how many flowers have been planted
        for (int i = 0; i < size; i++) // iterate through each spot in the flowerbed
        {
            if (flowerbed[i] == 0) // if the current spot is empty
            {
                if (i == 0) // if it's the first spot
                {
                    if (size == 1) // if it's the only spot in the flowerbed
                    {
                        counting++; // plant a flower
                        break; // exit the loop
                    }
                    if (flowerbed[i + 1] == 0) // if the next spot is also empty
                    {
                        counting++; // plant a flower
                        flowerbed[i] = 1; // mark the current spot as planted
                    }
                }
                else if (i == size - 1) // if it's the last spot
                {
                    if (flowerbed[i - 1] == 0) // if the previous spot is empty
                    {
                        counting++; // plant a flower
                        flowerbed[i] = 1; // mark the current spot as planted
                    }
                }
                else // if it's a spot in the middle
                {
                    if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) // if both the previous and next spots are empty
                    {
                        counting++; // plant a flower
                        flowerbed[i] = 1; // mark the current spot as planted
                    }
                }
            }
        }
        return counting >= n; // return true if we've planted enough flowers, false otherwise
    }
};
