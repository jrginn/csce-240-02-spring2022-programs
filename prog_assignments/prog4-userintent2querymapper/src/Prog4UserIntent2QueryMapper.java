import org.apache.commons.text.similarity.LevenshteinDistance;
import java.io.*;
import java.util.Scanner;

public class Prog4UserIntent2QueryMapper {

	public static Scanner keyboard = new Scanner(System.in);
	public static LevenshteinDistance ldist = new LevenshteinDistance();
	
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
		//supported queries
		String[] queries = {"tell me about the rep", "where does the rep live", "how do I contact my rep", "what committees is my rep on", "tell me everything"};
		//welcomes user
		System.out.println("Hello! What questions do you have about Representative Hixon?");
		while(true) {
			//takes input
			String input = keyboard.nextLine();
			if(ldist.apply(input.toLowerCase(), "quit") <= 2 || ldist.apply(input.toLowerCase(), "quit") <= 2) {
				System.out.println("Goodbye.");
				break;
			}
			String potentialMatch = queryCompare(input, queries);
			if(!potentialMatch.equals("invalid query")) {
				if(potentialMatch.equals(queries[0])) {
					//personal information
					System.out.println("Personal information: ");
					System.out.println(arr[8].toString());
				}
				else if(potentialMatch.equals(queries[1])) {
					//home address
					System.out.println("Home address: ");
					System.out.println(arr[4].toString());
				}
				else if(potentialMatch.equals(queries[2])) {
					//contact information
					System.out.println("Contact information: ");
					System.out.println(arr[2].toString());
					System.out.println(arr[3].toString());
					System.out.println(arr[4].toString());
					System.out.println(arr[5].toString());
				}
				else if(potentialMatch.equals(queries[3])) {
					//committee assignments
					System.out.println("Committee assignments: ");
					System.out.println(arr[9].toString());
				}
				else if(potentialMatch.equals(queries[4])) {
					//everything
					System.out.println("Everything: ");
					printEverything(arr);
				}
			}
			else {
				System.out.println("Your query was not understood.");
			}
		}
	}
	
	public static String queryCompare(String u, String[] valid) {
		//lowercases utterance
		u = u.toLowerCase();
		//checks if any whole queries are close matches
		String currentBest = ""; //current best matching query
		int currentLow = Integer.MAX_VALUE; //current lowest distance
		//loops through queries and finds closest to utterance
		for(String query : valid) {
			//calculates distance
			int d = ldist.apply(query, u);
			//distance is within threshold and utterance is closer than current lowest
			if(d <= 7 && d < currentLow) {
				//updates currents
				currentBest = query;
				currentLow = d;
			}
		}
		//found at least one query within threshold
		if(currentLow != Integer.MAX_VALUE) {
			return currentBest;
		}
		//splits u into different words
		String[] uWords = u.split(" ");
		String bestMatch = "";
		double highestMatchPercent = -1.0;
		//loops through queries, splitting them into words
		for(String query : valid) {
			int closeMatchCount = 0;
			for(String queryWord : query.split(" ")) {
				//compares words of each and checks if distance is within word threshold
				for(String curUWord : uWords) {
					int distance = ldist.apply(curUWord, queryWord);
					if(distance <= 3) {
						closeMatchCount++;
					}
				}
			}
			//adjusts closeMatchCount for length of query
			double matchPercent = (double)closeMatchCount / (double)query.length();
			//matchPercent is within the threshold and is higher than the previous max
			if(matchPercent >= .7 && matchPercent > highestMatchPercent) {
				//updates variables
				bestMatch = query;
				highestMatchPercent = matchPercent;
			}
		}
		//a match was found
		if(!bestMatch.equalsIgnoreCase("")) {
			return bestMatch;
		}
		//a match was not found
		return "invalid query";
	}
	
	
	public static void printEverything(InfoSet[] sets) {
		//loops through array and prints each element
		for(InfoSet is : sets) {
			System.out.println(is.toString());
		}
	}
}
