//Jackson Ginn
import java.io.*;
import java.util.Scanner;
import org.apache.commons.text.similarity.LevenshteinDistance;
import java.time.*;
import java.time.format.*;
public class Chatbot {

	public static Scanner keyboard = new Scanner(System.in);
	public static final String delim = "DELIM";
	public static LevenshteinDistance ldist = new LevenshteinDistance();
	
	public static void main(String[] args) {
		if(args.length == 0) {
			//session count is the number of current sessions plus one
			int sessionCount = new File("data/chat_sessions").list().length + 1;
			//gets date and time and creates file name for session
			DateTimeFormatter dtf = DateTimeFormatter.ofPattern("MM/dd/yyyy HH:mm:ss");  
			LocalDateTime now = LocalDateTime.now();
			String date = dtf.format(now).split(" ")[0].split("/")[0] + "-" + dtf.format(now).split(" ")[0].split("/")[1] + "-" + dtf.format(now).split(" ")[0].split("/")[2].substring(2);
			String time = dtf.format(now).split(" ")[1].split(":")[0] + "-" + dtf.format(now).split(" ")[1].split(":")[1];
			String sessionName = date + "_" + time + ".txt";
			//creates file to write output to
			PrintWriter fileWriter = null;
			try {
				fileWriter = new PrintWriter(new FileOutputStream("data/chat_sessions/" + sessionName));
			} catch (FileNotFoundException e) {
				return;
			}
			Scanner outFile = null;
			//if the input file exists, it initializes a scanner
			try {
				outFile = new Scanner(new File("data/hixonOutput.txt"));
			}
			catch(FileNotFoundException f) {
				//if the file does not exist, it creates it and then runs the method again
				writeFormatFile();
				main(args);
			}
			//formats output file into a string for processing
			String formatString = formatOutput(outFile);
			String[] outputSections = formatString.split(delim);
			//creates InfoSet array equal to number of output sections
			InfoSet[] infoSets = new InfoSet[outputSections.length];
			//fills array
			for(int i = 0; i < infoSets.length; i++) {
				infoSets[i] = new InfoSet(outputSections[i]);
			}
			//valid queries
			String[] queries = {"tell me about the rep", "where does the rep live", "how do I contact my rep", "what committees is my rep on", "tell me everything", "what district do you support"};
			//counters for utterance
			int userUtterance = 0;
			int sysUtterance = 0;
			int startTime = (int) System.currentTimeMillis();
			System.out.println("Hello! What are your questions about the rep?");
			fileWriter.println("Hello! What are your questions about the rep?");
			sysUtterance++;
			while(true) {
				//takes input
				String input = keyboard.nextLine();
				fileWriter.println(input);
				userUtterance++;
				if(ldist.apply(input.toLowerCase(), "quit") <= 2 || ldist.apply(input.toLowerCase(), "quit") <= 2) {
					System.out.println("Goodbye.");
					fileWriter.print("Goodbye.");
					sysUtterance++;
					break;
				}
				String potentialMatch = queryCompare(input, queries);
				if(!potentialMatch.equals("invalid query")) {
					if(potentialMatch.equals(queries[0])) {
						//personal information
						System.out.println("Personal information: ");
						System.out.println(infoSets[8].toString());
						fileWriter.println("Personal information: ");
						fileWriter.println(infoSets[8].toString());
					}
					else if(potentialMatch.equals(queries[1])) {
						//home address
						System.out.println("Home address: ");
						System.out.println(infoSets[4].toString());
						fileWriter.println("Home address: ");
						fileWriter.println(infoSets[4].toString());
					}
					else if(potentialMatch.equals(queries[2])) {
						//contact information
						System.out.println("Contact information: ");
						System.out.println(infoSets[2].toString());
						System.out.println(infoSets[3].toString());
						System.out.println(infoSets[4].toString());
						System.out.println(infoSets[5].toString());
						fileWriter.println("Contact information: ");
						fileWriter.println(infoSets[2].toString());
						fileWriter.println(infoSets[3].toString());
						fileWriter.println(infoSets[4].toString());
						fileWriter.println(infoSets[5].toString());
					}
					else if(potentialMatch.equals(queries[3])) {
						//committee assignments
						System.out.println("Committee assignments: ");
						System.out.println(infoSets[9].toString());
						fileWriter.println("Committee assignments: ");
						fileWriter.println(infoSets[9].toString());
					}
					else if(potentialMatch.equals(queries[4])) {
						//everything
						System.out.println("Everything: ");
						fileWriter.println("Everything: ");
						printEverything(infoSets);
						fileWriter.println(collectEverything(infoSets));
					}
					else if(potentialMatch.equals(queries[5])) {
						//supported district 
						System.out.println("District 83: Aiken and Edgefield Counties");
						fileWriter.println("District 83: Aiken and Edgefield Counties");
					}
				}
				else {
					System.out.println("Your query was not understood.");
					fileWriter.println("Your query was not understood.");
				}
				sysUtterance++;
			}
			int stopTime = (int) System.currentTimeMillis();
			int totalTime = (stopTime - startTime) / 1000;
			PrintWriter csvWriter = null;
			try {
				csvWriter = new PrintWriter(new FileOutputStream("data/chat_statistics.csv", true));
			} catch (FileNotFoundException e) {
				System.out.println("Statistics file not found");
				fileWriter.close();
				return;
			}
			csvWriter.println(sessionCount + "," + sessionName + "," + userUtterance + "," + sysUtterance + "," + totalTime);
			fileWriter.close();
			csvWriter.close();
		}
		else {
			//initializes file variables
			File statistics = new File("data/chat_statistics.csv");
			//checks for each possible argument
			if(args[0].equals("-summary")) {
				summarizeAll(statistics);
			}
			else if(args[0].equals("-showchat")) {
				//ensures that a specific chat was given
				try {
					int index = Integer.parseInt(args[1]);
					showchat(statistics, index);
				}
				catch(ArrayIndexOutOfBoundsException a) {
					System.out.println("No chat specified");
					return;
				}
			}
			else if(args[0].equals("-showchat-summary")) {
				//ensures that a specific chat was given
				try {
					int index = Integer.parseInt(args[1]);
					summarizeSpecific(statistics, index);
				}
				catch(ArrayIndexOutOfBoundsException a) {
					System.out.println("No chat specified");
					return;
				}
			}
			else {
				System.out.println("Invalid argument");
			}
		}
	}
	
	public static void writeFormatFile() {
		String inputFileName = "data/hixonInput.txt";
		Scanner fileScanner;
		try {
			fileScanner = new Scanner(new File(inputFileName));
		} catch (FileNotFoundException e) { //file does not exist so the program cannot run
			System.out.println("The file could not be found.");
			return;
		}
		//fileLine takes values from file, previousFileLine stores the line before the current to check if indentation is necessary
		String fileLine;
		String previousFileLine = "";
		//outputLine is the line that goes to the output file and is printed out
		String outputLine;
		//fileWriter updates the output file
		PrintWriter fileWriter;
		try {
			fileWriter = new PrintWriter(new FileOutputStream("data/hixonOutput.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		while(fileScanner.hasNextLine()) { //goes through file
			fileLine = fileScanner.nextLine();
			//if the previous line was not empty and was not just a space, then the line is indented to show it is data
			if(!previousFileLine.equals("") && !previousFileLine.equals(" ")) {
				outputLine = "\t" + fileLine;
			}
			else { //otherwise, the line is not indented to show it is a header
				outputLine = fileLine;
			}
			//the line is put into the file, and then the line is stored for the next
			fileWriter.println(outputLine);
			previousFileLine = fileLine;
		}
		fileScanner.close();
		fileWriter.close();
	}
	
	public static String formatOutput(Scanner output) {
		String ret = "";
		while(output.hasNextLine()) { //goes through file and formats it to prepare for processing
			String fileLine = output.nextLine();
			if(!fileLine.equals("\t")) {
				ret += fileLine;
			}
			else {
				ret += delim;
			}
		}
		return ret;
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
		//a match was not found
		return "invalid query";
	}
	
	public static void printEverything(InfoSet[] sets) {
		//loops through array and prints each element
		for(InfoSet is : sets) {
			System.out.println(is.toString());
		}
	}
	
	//compiles all information into a string to be written to a file
	public static String collectEverything(InfoSet[] sets) {
		String ret = "";
		for(InfoSet is: sets) {
			ret += is.toString();
		}
		return ret;
	}
	
	public static void summarizeAll(File stats) {
		//initializes variables
		Scanner statReader;
		int userCount = 0;
		int systemCount = 0;
		int totalTime = 0;
		int lineCount = 0;
		try {
			statReader = new Scanner(stats);
		} 
		catch (FileNotFoundException e) {
			System.out.println("Missing chat statistics file");
			return;
		}
		//skips first line
		statReader.nextLine();
		//loops through csv lines
		while(statReader.hasNextLine()) {
			String line = statReader.nextLine();
			lineCount++;
			//splits into each data point and adds to totals
			String[] data = line.split(",");
			userCount += Integer.parseInt(data[2]);
			systemCount += Integer.parseInt(data[3]);
			totalTime += Integer.parseInt(data[4]);
			
		}
		//prints totals
		System.out.println("There are " + lineCount + " chats to date with user asking " + userCount + " times and system responding " + 
		systemCount + " times. Total duration is " + totalTime + " seconds.");
		statReader.close();
	}
	
	public static void summarizeSpecific(File stats, int x) {
		//initializes variables
		Scanner statReader;
		int userCount = 0;
		int systemCount = 0;
		int time = 0;
		boolean found = false;
		try {
			statReader = new Scanner(stats);
		} 
		catch (FileNotFoundException e) {
			System.out.println("Missing chat statistics file");
			return;
		}
		//skips first line
		statReader.nextLine();
		//loops through csv lines
		while(statReader.hasNextLine()) {
			String line = statReader.nextLine();
			String[] data = line.split(",");
			//chat number matches requested number
			if(Integer.parseInt(data[0]) == x) {
				found = true;
				userCount += Integer.parseInt(data[2]);
				systemCount += Integer.parseInt(data[3]);
				time += Integer.parseInt(data[4]);
			}
		}
		if(found) {
			System.out.println("Chat " + x + " has user asking " + userCount + " times and system responding " + systemCount + 
					" times. Total duration is " + time + " seconds.");
		}
		else {
			System.out.println("Chat " + x + " does not exist");
			statReader.close();
			return;
		}
		statReader.close();
	}
	
	public static void showchat(File stats, int x) {
		Scanner statReader;
		String filename = "";
		boolean found = false;
		try {
			statReader = new Scanner(stats);
		} 
		catch (FileNotFoundException e) {
			System.out.println("Missing chat statistics file");
			return;
		}
		//skips first line
		statReader.nextLine();
		//loops through csv lines
		while(statReader.hasNextLine()) {
			String line = statReader.nextLine();
			String[] data = line.split(",");
			//chat number matches requested number
			if(Integer.parseInt(data[0]) == x) {
				found = true;
				filename = "data/chat_sessions/" + data[1];
			}
		}
		if(!found) {
			System.out.println("Chat " + x + " does not exist");
			statReader.close();
			return;
		}
		//if the file exists, it prints each line
		Scanner chat;
		try {
			chat = new Scanner(new File(filename));
			String chatLine = "";
			System.out.println("Chat " + x + " chat is:");
			while(chat.hasNextLine()) {
				chatLine = chat.nextLine();
				System.out.println(chatLine);
			}
			
			chat.close();
		} 
		catch (FileNotFoundException e) {
			System.out.println("Chat file not found");
		}
		statReader.close();
	}
}
