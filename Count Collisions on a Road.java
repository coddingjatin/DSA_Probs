class Solution {
    public int countCollisions(String s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j && s.charAt(i) == 'L')
        {
             i++;
        }  
        while (i <= j && s.charAt(j) == 'R')
        { 
            j--;
        }
        int collisions = 0;
        for (int k = i; k <= j; k++) {
            if (s.charAt(k) != 'S'){
                collisions++;
            } 
        }
     return collisions;
    }
}
