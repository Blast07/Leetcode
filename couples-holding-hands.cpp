class Solution {
public:
    int minSwapsCouples(vector <int> &row){
	 int i = 0;
        int swaps = 0;

        int pos[70];
        for(i = 0; i < row.size(); i++)
            pos[row[i]] = i;

        i = 0;
        while (i < row.size()-1)
        {
            int X0 = row[i];
            int X1 = (X0 % 2 == 0) ? X0 + 1 : X0 - 1;
            
            int j = i+1;
            if (row[j] != X1)
            {
                int temp = row[j];
                row[pos[X1]] = temp;
                pos[temp] = pos[X1];
                swaps++;
            }
            i += 2;
        }
        return swaps;
	
}

};