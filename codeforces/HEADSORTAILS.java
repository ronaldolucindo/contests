/* 

HEADSORTAILS - A. Heads or Tails
http://codeforces.com/problemset/problem/242/A
RONALDO MEDEIROS LUCINDO

*/

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;


public class Headsortails {
       
   
    public static void main(String[] args) {
        Scanner console;
        console= new Scanner(System.in);
        int x, y, a, b, resultadosPossiveis=0;
        x=console.nextInt();
        y=console.nextInt();
        a=console.nextInt();
        b=console.nextInt();
        ArrayList<Integer> petya = new ArrayList();
        ArrayList<Integer> vasya = new ArrayList();
        for(int i=a; i<=x; i++){
            for(int j=b; j<=y; j++){
                if(i>j){
                    resultadosPossiveis++;
                    petya.add(j);
                    vasya.add(i);
                }
            }
        }
        System.out.println(resultadosPossiveis);
        Iterator<Integer> i = vasya.iterator();
        Iterator<Integer> j = petya.iterator();
        while(i.hasNext() && j.hasNext()){
            System.out.println(i.next()+" "+j.next());
        }
        
            
        
    }
    
}