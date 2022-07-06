    #include<stdio.h>
    #include<stdlib.h>
    struct myArray
    {
        int total_size;
        int used_size;
        int *ptr;

    };
    /*
    Operation on Array
    1. Traversal
    2. Insertion
    3. Deletion
    4. Searching
    5. Sorting
    */
    void createArray(struct myArray * a, int tSize,int uSize)
    {
        //(*a).total_size = tSize;
        //(*a).used_size = uSize;
        //(*a).ptr = (int *) malloc(tSize*sizeof(int));

        a -> total_size = tSize;
        a -> used_size = uSize;
        a -> ptr = (int *) malloc(tSize*sizeof(int));
    }

    void show(struct myArray *a)
    {
        for(int i =  0 ; i < a->used_size ; i++)
        {
            printf("%d\n", (a -> ptr)[i] );
        }
    }

    void setVal(struct myArray *a)
    {
        int n;
        for(int i =  0 ; i < a->used_size ; i++)
        {
            //printf("Enter Element %d ", i);
            scanf("%d\n",&n );
            (a -> ptr)[i] = n;
        }
    }

    void solve()
    {
       struct myArray marks;
       createArray(&marks,10,2);
       printf("We are running setVal now\n");
       setVal(&marks);
       printf("We are running show now\n");
       show(&marks);
    }



    int main()
    {

        solve();
        return 0;
    }

