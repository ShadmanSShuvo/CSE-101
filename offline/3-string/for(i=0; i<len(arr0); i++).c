for(i=0; i<len(arr0); i++){
                a[tolower(arr0[i]) - 'a']++;
            }
            for(i=0; i<len(perm); i++){
                a[tolower(perm[i]) - 'a']--;
            }
            for(i=0; i<26; i++){
                if(a[i]!=0){
                    printf("Your guess: %s\n",t);
                    printf("Incorrect! Try again.");
                    c0++;
                    break;
                }
            }
            if(i==26) printf("Correct! You solved it in %d attempt(s).", c0);