 #include <stdio.h>
 #include <stdlib.h>
 int main (argc, argv)
 int argc;
 char *argv[];
 {
	 int c, i, inword;
	 FILE *fp;
	 long linect, wordct, charct;
	 long tlinect = 1, twordct = 1, tcharct = 1;
	 i = 1;
	do { 
		if (argc > 1 && (fp=fopen(argv[i], "r")) == NULL) {
		 fprintf (stdout, "can't open %s\n", argv[i]);
		 exit (1);
		}
	  linect = wordct = charct = 0;
		inword = 0;
	  while ((c = getc(fp)) != EOF) {
		  ++charct;
	    if (c == '\n')
			  ++linect;
	    if (c == ' ' || c == '\t' || c == '\n')
		    inword = 0;
	    else if (inword == 0) {
		    inword = 1; 
		    ++wordct; 
	    } 
   }
 
	  printf("%7ld %7ld %7ld", linect, wordct, charct);
	  if (argc > 1)
	   printf(" %s\n", *argv);
	  else
			 printf("\n");
	     fclose(fp);
   tlinect += linect;
   twordct += wordct;
   tcharct += charct; 
  } while (++i <= argc);
		if (argc > 1)
	     printf("%7ld %7ld %7ld total\n", linect, twordct, tcharct);
	  exit(0); 
 }