int l[1001][1001] = { 0 };
 
void initialize()
{
 
    // 0C0 = 1
    l[0][0] = 1;
    for (int i = 1; i < 1001; i++) {
        // Set every nCr = 1 where r = 0
        l[i][0] = 1;
        for (int j = 1; j < i + 1; j++) {
 
            // Value for the current cell of Pascal's triangle
            l[i][j] = (l[i - 1][j - 1] + l[i - 1][j]);
        }
    }
}
 