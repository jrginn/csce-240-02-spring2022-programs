//Jackson Ginn
import java.io.*;
import java.util.Scanner;

public class Prog5SessionLogger {
	
	public static Scanner keyboard = new Scanner(System.in);

	public static void main(String[] args) {
		//initializes file variables
		File statistics = new File("data/chat_statistics.csv");
		//no arguments
		if(args.length < 1) {
			System.out.println("No arguments");
			return;
		}
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
