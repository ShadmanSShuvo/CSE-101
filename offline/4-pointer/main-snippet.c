char a[100], t[100];
    
    scanf(" %[^\n]s", a);

    int i = strlen(s) - 1; 
    int j = 0;
    int c;

    while (i >= 0 && isspace(a[i])) {
        i--;
    }

    
    while (i >= 0) {
        c = 0; 
        while (i >= 0 && !isspace(a[i])) {
            i--;
            c++;
        }

        
        for (int k = i + 1; k <= i + c; k++) {
            t[j++] = a[k];
        }

        
        while (i >= 0 && isspace(a[i])) {
            i--;
        }

        
        if (i >= 0) {
            t[j++] = ' ';
        }
    }

    
    t[j] = '\0';

    
    printf("\"%s\"\n", t);