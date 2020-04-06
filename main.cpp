#include <stdint.h>
#include <cstdio>

uint8_t subsetSum(uint32_t array[], uint32_t n, uint32_t k, uint32_t v)
{
    if(k == 0 && v == 0)
    {
        return true;
    }
    else if(k == 0)
    {
        return false;
    }
    else if (n == 0)
    {
        return false;
    }
    uint8_t tempRes = 0;
    if(array[0] <= v)
    {
        tempRes = subsetSum(&array[1], n-1, k-1, v-array[0]);
    }
    uint8_t tempRes2 = subsetSum(&array[1], n-1, k, v);
    if(tempRes + tempRes2 > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main() {
    uint32_t array[] = {1, 8, 6, 4, 3};
    printf("%d", subsetSum(array, 5, 3, 9));
    printf("\n");
    printf("%d", subsetSum(array, 5, 2, 9));
    printf("\n");
    printf("%d", subsetSum(array, 5, 1, 4));
    return 0;
}
