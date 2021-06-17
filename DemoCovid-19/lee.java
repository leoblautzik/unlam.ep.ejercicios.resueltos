import java.io.*;
public class LeerUsarSplit{
	public static void main(String args[]){
		try{
			FileReader input = new FileReader(new File("myArchivo.in"));
			BufferedReader bufInput = new BufferedReader(input);
			String line;
			String s="2";
			String a="ala";
			line = bufInput.readLine();
			while(line != null){
				String [] datos;
				datos = line.split(",");
				int entero1 = Integer.parseInt(datos[0]);
				int entero2 = Integer.parseInt(datos[1]);
				
				if(datos.length == 3){
					int entero3 = Integer.parseInt(datos[2]);
					System.out.println("" + entero1 + " " + entero2 + " " + entero3);
				}
				else{
					System.out.println("" + entero1 + " " + entero2);
				}
				line = bufInput.readLine();
			}
			bufInput.close();
		} catch (IOException e){
			e.printStackTrace();
		}
	}
}

