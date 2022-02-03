//Written by Jackson Ginn
import java.io.*;
import java.util.InputMismatchException;
import java.util.Scanner;
public class DataCollector {
	
	public static Scanner keyboard = new Scanner(System.in);
	
	public static void main(String[] args) {
		//welcomes user and takes their name
		System.out.println("Hello! What is your name?");
		String name = keyboard.nextLine();
		//Gets district of interest from user
		System.out.println(name + ", what district are you interested in?");
		int districtChoice = 83; //default value
		try {
			districtChoice = keyboard.nextInt();
		}
		catch (InputMismatchException e) { //handles user inputting a non-number
			System.out.println("You did not input a number, so we will use the default, which is 83");
		}
		if(districtChoice != 83) { //no info about other districts
			System.out.println("This district is not currently supported");
			return;
		}
		System.out.println("You chose District 83, which is represented by William Hixon.");
		//initializes file information
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
			//the line is printed and put into the file, and then the line is stored for the next
			System.out.println(outputLine);
			fileWriter.println(outputLine);
			previousFileLine = fileLine;
		}
		keyboard.close();
		fileScanner.close();
		fileWriter.close();
	}
}
