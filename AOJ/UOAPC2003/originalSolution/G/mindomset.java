
import java.io.*;
import java.lang.*;

public class mindomset {
	public static void main(String[] args) throws IOException {
		int [] heads = new int[88], tails = new int[88];
		int [] results = new int[20], signs = new int[20], resu2 = new int[20];
		int mds = 9999;
		int NV=0, NL =0;
		try {
	   	   	FileReader fr     = new FileReader("dominset.txt");
	       	BufferedReader br = new BufferedReader(fr);
		   	String line = br.readLine();
			// Number of Vertices
			NV = Integer.parseInt(line.substring(0,line.indexOf(",")).trim());
			// Number of links
			NL = Integer.parseInt(line.substring(line.indexOf(",")+1).trim());
		   	int i = 0;
	       	while ((line = br.readLine()) != null) {
			while(line.indexOf(",") >0) {
				heads[i] = Integer.parseInt(line.substring(0,line.indexOf(" ")).trim());
				tails[i] = Integer.parseInt(line.substring(line.indexOf(" ")+1, line.indexOf(",")).trim());
				i++;
				line = line.substring(line.indexOf(",")+2).trim();
			}
            }
		} catch (IOException e) {}

		//System.out.println("Input: " + NV + ", "+NL);
 		
 		// greedy algorithm
        int v = 0;
        for (int i=0; i<NV; i++) {
         	results[i] = 1;
         	resu2[i] = 0;
         	signs[i] = 0;
        }
        for (int i=0; i<NL; i++) {
         	results[heads[i]]++;
         	results[tails[i]]++;
        }

        int k = 1;
        while (k<NV) {
			long m1 = Math.round(Math.pow(NV,k))-1;
			while (m1 >=0) {
		        for (int i=0; i<NV; i++) {
    	    	 	resu2[i] = -1;
        	 		signs[i] = 0;
        		}
				for (int i=0; i<k;i++){
					long m2 = Math.round(Math.pow(NV,i));
					resu2[i] = ((int)(m1/m2)) % NV;
				}

		 		int i1=0;
	 			int tmp=0;
		 		while (resu2[i1] >=0) {
         	 		tmp += resu2[i1];
         	 		i1++;
         	 	}
				i1 = 0;
       	 		if (tmp > NV-1) {
			 		while (resu2[i1] >=0) {
         	 			int m = resu2[i1];
         	 			signs[m] = 1;
         	   			for (int j=0; j<NL; j++) {
           	   				if (heads[j] == m) signs[tails[j]] = 1;
           	 				if (tails[j] == m) signs[heads[j]] = 1;
         				}
	        	 		i1++;
         	 		}
	         	}
       		 	v = 0;
         	   	for (int j=0; j<NV; j++) {
           	    	if (signs[j] == 0) {
               			v = 1;
           	 		}
         	 	}
         	 	if (v == 0) {
					i1 = 0;
	         		// System.out.print("\nMinimum Dominating Set ");
			 		while (resu2[i1] >=0) {
		         	// System.out.print(" NV" + resu2[i1]);
        	 	 		i1++;
         		 	}
					if (mds > i1) mds = i1;	
         	 		break;
         	 	}

				m1--;
			}
         	k++;
        }
       	System.out.println(" " + mds);

  	}
}