import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

//Written by Jackson Ginnn
public class DataProcessor {
	
	public static Scanner keyboard = new Scanner(System.in);
	public static final String delim = "DELIM";
	
	public static void main(String[] args) {
		if(args.length != 1) {
			System.out.println("Invalid number of arguments");
			return;
		}
		//initializes file object
		Scanner fileScanner;
		try {
			fileScanner = new Scanner(new File("data/hixonOutput.txt"));
		} catch (FileNotFoundException e) { //file does not exist so the program cannot run
			System.out.println("The file could not be found.");
			return;
		}
		//formats output file into a string and then splits the string based on the delimiter
		String formattedOutput = formatOutput(fileScanner);
		String[] outputSections = formattedOutput.split(delim);
		//creates InfoSet array equal to number of output sections
		InfoSet[] infoSets = new InfoSet[outputSections.length];
		//fills array
		for(int i = 0; i < infoSets.length; i++) {
			infoSets[i] = new InfoSet(outputSections[i]);
		}
		checkRequest(args[0], infoSets);
		//closes scanners
		keyboard.close();
		fileScanner.close();
	}
	
	//takes output file scanner and returns a delimited string used to create InfoSets
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
	
	//goes through each InfoSet and checks if they match the request
	public static void checkRequest(String request, InfoSet[] data) {
		//splits request based on colon
		String[] splitRequest = request.split(":");
		//first part is general section, second is specific info
		if(splitRequest.length == 2) {
			Pattern p = Pattern.compile(splitRequest[0]);
			//checking for title
			for(InfoSet i : data) {
				Matcher m = p.matcher(i.getTitle());
				if(m.find()) {
					System.out.println(i.getTitle());
					Pattern q = Pattern.compile(splitRequest[1]);
					//checking for specific info
					for(String fact : i.getFacts()) {
						Matcher n = q.matcher(fact);
						if(n.find()) {
							System.out.println(fact);
						}
					}
				}
			}
		}
		else if(splitRequest.length == 1) { //checking for general section only since that was all that was passed
			Pattern p = Pattern.compile(request);
			for(InfoSet i : data) {
				Matcher m = p.matcher(i.getTitle());
				if(m.find()) {
					System.out.println(i.toString());
				}
			}
		}
	}
	
}