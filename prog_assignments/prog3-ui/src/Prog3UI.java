//Written by Jackson Ginn
import java.io.*;
import java.util.Scanner;
import java.util.regex.*;
public class Prog3UI {
	
	public static Scanner keyboard = new Scanner(System.in);
	
	public static void main(String[] args) {
		//deserializes objects from DataProcessors
		InfoSet[] arr;
		try {
			FileInputStream fileIn = new FileInputStream("data/sets.ser");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			arr = (InfoSet[]) in.readObject();
			fileIn.close();
			in.close();
		}
		catch(IOException i) {
			i.printStackTrace();
			return;
		}
		catch(ClassNotFoundException c) {
			c.printStackTrace();
			return;
		}
		//welcomes user
		System.out.println("Hello! What questions do you have about Representative Hixon?");
		//loops until user tells it to stop
		while(true) {
			String query = keyboard.nextLine();
			if(query.equalsIgnoreCase("quit") || query.equalsIgnoreCase("q")) {
				break;
			}
			if(!searchData(query, arr)) {
				System.out.println("I cannot handle that query.");
			}
			System.out.println("What other questions do you have?");
		}
		System.out.println("Thank you!");
	}
	
	public static boolean searchData(String request, InfoSet[] data) {
		boolean found = false;
		//loops through titles
		for(int i = 0; i < data.length; i++) {
			String currentTitle = data[i].getTitle();
			Pattern p = Pattern.compile(currentTitle.toLowerCase());
			Matcher m = p.matcher(request.toLowerCase());
			if(m.find()) {
				System.out.println(currentTitle);
				found = true;
				if(data[i].getFacts() != null) {
					for(int j = 0; j < data[i].getFacts().length; j++) {
						found = true;
						System.out.println(data[i].getFacts()[j]);
					}
				}
			}
		}
		//loops through each facts array and checks each fact
		for(int i = 0; i < data.length; i++) {
			if(data[i].getFacts() != null) {
				for(int j = 0; j < data[i].getFacts().length; j++) {
					String currentFact = data[i].getFacts()[j];
					Pattern p = Pattern.compile(currentFact.toLowerCase());
					Matcher m = p.matcher(request.toLowerCase());
					if(m.find()) {
						System.out.println(currentFact);
						found = true;
					}
				}
			}
		}
		//if it still has not found anything, it checks each word of the title for a match
		if(!found) {
			for(int i = 0; i < data.length; i++) {
				String[] titleWords = data[i].getTitle().split(" ");
				for(int j = 0; j < titleWords.length; j++) {
					//avoids partial matches with things like "M."
					if(titleWords[j].length() >= 4) {
						Pattern p = Pattern.compile(titleWords[j].toLowerCase());
						Matcher m = p.matcher(request.toLowerCase());
						if(m.find()) {
							found = true;
							System.out.println(data[i].getTitle());
							if(data[i].getFacts() != null) {
								for(int k = 0; k < data[i].getFacts().length; k++) {
									System.out.println(data[i].getFacts()[k]);
								}
							}
						}
					}
				}
			}
		}
		//if it still has not found anything, it checks each word of each fact
		if(!found) {
			for(int i = 0; i < data.length; i++) {
				if(data[i].getFacts() != null) {
					for(int j = 0; j < data[i].getFacts().length; j++) {
						String[] splitFact = data[i].getFacts()[j].split(" ");
						for(int k = 0; k < splitFact.length; k++) {
							if(splitFact[k].length() >= 4) {
								Pattern p = Pattern.compile(splitFact[k].toLowerCase());
								Matcher m = p.matcher(request.toLowerCase());
								if(m.find()) {
									found = true;
									System.out.println(data[i].getFacts()[j]);
								}
							}
						}
					}
				}
			}
		}
		return found;
	}
	
}
