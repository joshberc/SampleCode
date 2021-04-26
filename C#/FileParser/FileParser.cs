//Written By Josh Berc - 21/4/2021
using System;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using System.Collections.Generic;

namespace FileParser
{
    class Program
    {
        #region --- Main ---
        /// <summary>
        /// Main function. Takes user input and calls search function.
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            //--- Variables ---
            string filePath = Directory.GetCurrentDirectory() + @"\TestWords.txt";
            string[] fileData;
            List<string> regexData = new List<string>();
            string wordSearch = "search";


            //Read and Regex data to be all lowercase.
            fileData = File.ReadAllLines(filePath);
     
            foreach (string line in fileData)
            {
                //Clears empty lines.
                if (!string.IsNullOrWhiteSpace(line))
                {
                    string temp = line;
                    temp = temp.ToLower();
                    regexData.Add(temp);
                }
            }

            //Takes user input for word they would like to search for.
            Console.WriteLine("- Welcome to Word Search -");
            Console.WriteLine("Reading from text file: "+filePath);
            Console.WriteLine("What word would you like to search for?");
            wordSearch = Console.ReadLine().ToLower();

            //Calculate word occurence and output it to the console.
            Console.WriteLine("The word "+wordSearch+", occured "+WordOccurence(wordSearch, regexData)+" time(s) in the given text file.");
            Console.WriteLine("Press any Enter to exit.");
            Console.ReadLine();
        }
        #endregion

        #region --- Functions ---
        /// <summary>
        /// Searchs the data string for the occurence of wordCheck. Returns total count.
        /// </summary>
        /// <param name="wordCheck">Word to search for.</param>
        /// <param name="data">String of regexed data to be searched.</param>
        /// <returns></returns>
        static int WordOccurence(string wordCheck, List<string> dataList)
        {
            //--- Variables ---
            Dictionary<string, int> dict = new Dictionary<string, int>();
            bool isPrevLineComment = false;
            bool isComment = false;

            foreach (string data in dataList)
            {
                //Splits string into elements, delimited by spaces.
                List<string> words = data.Split(' ').ToList();
                Console.WriteLine(isPrevLineComment);
                //Only adds to dictionary if the line is a comment.
                if (words.Contains("///") || words.Contains("//") || words.Contains("/*") || words.Contains("*") || words.Contains("*/") || isPrevLineComment)
                {
                    //Iterates through line.
                    foreach (string word in words)
                    {
                        //Toggles if section is comment or not.
                        if (word == "///" || word == "//" || word == "/*" || word == "*" || word == "*/" || isPrevLineComment)
                        {
                            
                            //For Multiline comments
                            if (word == "/*")
                            {
                                isPrevLineComment = true;
                            }
                            else if (word == "*/")
                            {
                                isComment = false;
                                isPrevLineComment = false;
                            }
                            else
                            {
                                isComment = true;
                            }
                        }
                        
                        /*
                         Comment
                        comment
                        */

                        if (isComment)
                        {
                            //Adds values that are in a comment
                            if (!dict.ContainsKey(word))
                            {
                                dict.Add(word, 1);
                                Console.WriteLine("Adding word: " + word);
                            }
                            else
                            {
                                //Adds one to this value in the dictionary
                                dict[word]++;
                            }
                        }

                    }

                }

                else { 
                    //If line is or does not contain a comment.
                    isPrevLineComment = false;
                } 

            }

            //Checks if key in Dictionary, if not returns 0.
            if (dict.ContainsKey(wordCheck))
            {
                return dict[wordCheck];
            }
            return 0;
        }
        #endregion
    }
}
