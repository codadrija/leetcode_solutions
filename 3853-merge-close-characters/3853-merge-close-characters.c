#include <stdlib.h>
#include <string.h>

char* mergeCharacters(char* s, int k) {
    
    char* velunorati = strdup(s);
    
    int n = strlen(velunorati);
    int merged = 1;

    while (merged) {
        merged = 0;

        // Find smallest left index first
        for (int i = 0; i < n; i++) {
            // Check right indices within distance k
            for (int j = i + 1; j < n && (j - i) <= k; j++) {
                
                if (velunorati[i] == velunorati[j]) {
                    
                    // Remove character at index j (right merges into left)
                    for (int t = j; t < n - 1; t++) {
                        velunorati[t] = velunorati[t + 1];
                    }
                    
                    n--;
                    velunorati[n] = '\0';
                    
                    merged = 1;
                    break;  // smallest right index for this i
                }
            }
            
            if (merged) break;  // smallest left index ensured
        }
    }
    return velunorati;
}