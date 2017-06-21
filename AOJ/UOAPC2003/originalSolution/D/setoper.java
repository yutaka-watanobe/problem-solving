import java.io.*;
import java.util.*;

public class setoper {

    boolean debug = false;
    static String fileName = "opset.txt";

    Set sets[] = new Set[6]; // A,B,C,D,E,U
    String expression;

    public static void main(String[] args) {

        new setoper();

    }

    setoper() {

        DataReader in = new DataReader(fileName);
        String exRPN;

        while (readData(in) != -1) {
            universal();
            exRPN = toReversePolish(expression);
            if (debug) System.out.println("RPN = " + exRPN);
            evaluateReversePolish(exRPN).printel();
        }
    }

    int readData(DataReader in) {

        int c, n, ns;
        char name;

        for (int i = 0; i < 6; i++) sets[i] = new Set();

        try {
            while (true) {
                name = in.nextStr().charAt(0);
                n = in.nextInt();
                if (debug) { System.out.println(name + " " + n);  }
                if (name == 'R')  break;
                ns = getSetNumber(name);
                sets[ns].allocate(n);
                for (int i = 0; i < n; i++) {
                    c = in.nextInt();
                    if (debug) System.out.print(c + " ");
                    sets[ns].add(c);
                }
                if (debug) System.out.println();
            }
            expression = in.nextStr();
            if (debug) System.out.println(expression);
        }
        catch (Throwable e) {
            return -1;
        }

        return 0;
    }

    int getSetNumber(char name) {

        int n;
        if      (name == 'A')  n = 0;
        else if (name == 'B')  n = 1;
        else if (name == 'C')  n = 2;
        else if (name == 'D')  n = 3;
        else if (name == 'E')  n = 4;
        else                   n = 5;
        return n;
    }

    String toReversePolish(String e) {

        Stack st = new Stack();
        char out[] = new char[e.length()];
        int lout = 0;
        char s, x;

        for (int i = 0; i < e.length(); i++) {
            s = e.charAt(i);
            if (s=='A' || s=='B' || s=='C' || s=='D' || s=='E' || s=='U') out[lout++] = s;
            else if (s == '(') st.push(e.substring(i, i + 1));
            else if (s == ')') {
                x = st.pop().toString().charAt(0);
                while (x != '(') {
                    out[lout++] = x;
                    x = st.pop().toString().charAt(0);
                }
            }
            else {
                while (!st.empty() && st.peek().toString().charAt(0) == 'c') {
                    x = st.pop().toString().charAt(0);
                    out[lout++] = x;
                }
                st.push(e.substring(i, i + 1));
            }
        }

        while (!st.empty()) {
            x = st.pop().toString().charAt(0);
            out[lout++] = x;
        }

        return new String(out, 0, lout);
    }


    Set evaluateReversePolish(String ex) {

        Stack st = new Stack();
        char s, x;

        for (int i = 0; i < ex.length(); i++) {
            s = ex.charAt(i);
            if (s=='A' || s=='B' || s=='C' || s=='D' || s=='E' || s=='U') {
                st.push(sets[getSetNumber(s)]);
            }
            else if (s == 'c') st.push(complement( (Set) st.pop()));
            else if (s=='u' || s=='i' || s=='d' || s=='s') {
                Set set2 = (Set) st.pop();
                Set set1 = (Set) st.pop();
                st.push(binaryOperation(set1, set2, s));
            }
        }
        return (Set) st.pop();
    }


    Set binaryOperation(Set s1, Set s2, char op) {
        Set s3 = null;
        if      (op == 'u')  s3 = union(s1, s2);
        else if (op == 'i')  s3 = intersection(s1, s2);
        else if (op == 'd')  s3 = difference(s1, s2);
        else if (op == 's')  s3 = symDifference(s1, s2);
        return s3;
    }

    Set union(Set s1, Set s2) {
        Set s3 = new Set(s1.ne + s2.ne);
        for (int i = 0; i < s1.ne; i++) s3.add(s1.e[i]);
        for (int j = 0; j < s2.ne; j++) {
            boolean exist = false;
            int e2 = s2.e[j];
            for (int i = 0; i < s1.ne; i++) {
                if (e2 == s1.e[i]) { exist = true; break; }
            }
            if (!exist) s3.add(e2);
        }
        return s3;
    }

    Set intersection(Set s1, Set s2) {
        Set s3 = new Set(Math.max(s1.ne, s2.ne));
        for (int j = 0; j < s2.ne; j++) {
            boolean exist = false;
            int e2 = s2.e[j];
            for (int i = 0; i < s1.ne; i++) {
                if (e2 == s1.e[i]) { exist = true; break; }
            }
            if (exist) s3.add(e2);
        }
        return s3;
    }

    Set difference(Set s1, Set s2) {
        Set s3 = new Set(s1.ne);
        for (int j = 0; j < s1.ne; j++) {
            boolean exist = false;
            int e1 = s1.e[j];
            for (int i = 0; i < s2.ne; i++) {
                if (e1 == s2.e[i]) { exist = true; break; }
            }
            if (!exist) s3.add(e1);
        }
        return s3;
    }

    Set symDifference(Set s1, Set s2) {
        Set s3 = new Set(s1.ne + s2.ne);
        for (int j = 0; j < s1.ne; j++) {
            boolean exist = false;
            int e1 = s1.e[j];
            for (int i = 0; i < s2.ne; i++) {
                if (e1 == s2.e[i]) { exist = true;  break; }
            }
            if (!exist) s3.add(e1);
        }
        for (int j = 0; j < s2.ne; j++) {
            boolean exist = false;
            int e2 = s2.e[j];
            for (int i = 0; i < s1.ne; i++) {
                if (e2 == s1.e[i]) { exist = true; break; }
            }
            if (!exist) s3.add(e2);
        }
        return s3;
    }

    void universal() {
        sets[5].allocate(sets[0].ne + sets[1].ne + sets[2].ne + sets[3].ne +sets[4].ne);
        for (int k = 0; k < 5; k++) {
            int n5 = sets[5].ne;
            for (int j = 0; j < sets[k].ne; j++) {
                boolean exist = false;
                int ek = sets[k].e[j];
                for (int i = 0; i < n5; i++) {
                    if (ek == sets[5].e[i]) { exist = true; break; }
                }
                if (!exist) sets[5].add(ek);
            }
        }
    }

    Set complement(Set s) {
        return difference(sets[5], s);
    }

}

class Set {

    int ne;
    int e[];

    Set() {
        ne = 0;
    }

    Set(int n) {
        ne = 0;
        e = new int[n];
    }

    void allocate(int n) {
        e = new int[n];
    }

    void add(int m) {
        e[ne++] = m;
    }

    void printel() {
        sort();
        if (ne == 0) System.out.print("NULL");
        else {
            for (int i = 0; i < ne; i++) {
                System.out.print(e[i] + " ");
            }
        }
        System.out.println();
    }

    void sort() {
        for (int j = 0; j < ne; j++) {
            int min = e[j];
            int imin = j;
            for (int i = j + 1; i < ne; i++) {
                if (e[i] < min) {
                    min = e[i];
                    imin = i;
                }
            }
            if (imin != j) {
                int t = e[j];
                e[j] = e[imin];
                e[imin] = t;
            }
        }
    }

}

class DataReader {

    FileReader in;

    DataReader(String fileName) {
        in = null;
        try {
            in = new FileReader(fileName);
        }
        catch (IOException e) {
            System.out.println("IO Exception: no file " + fileName);
        }
    }

    String nextToken() {
        StringBuffer sb = new StringBuffer();
        String token = "";
        try {
            int i = in.read();
            if(i==10) i = in.read();
            if(i==32 || i==9) {
                // -1 EOF, 10 LF, 13 CR, 32 SPACE, 9 TAB
                while( i!=-1 && (i==10 || i==13 || i==32 || i==9)) i = in.read();
            }
            while (i!=-1 && i!=10 && i!=13  && i!=32 && i!=9) {
                sb.append( (char) i);
                i = in.read();
            }
            token = sb.toString();
        }
        catch (IOException e) {
            System.out.println("IO Exception getting next token");
        }
        return token;
    }

    int nextInt() {
        return Integer.parseInt(nextToken());
    }

    String nextStr() {
        return nextToken();
    }

}