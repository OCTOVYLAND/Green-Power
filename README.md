# Green-Power
The system provide a possible percentage of how much a household can save from ever-growing electricity bill by using a self-sustaining solar systems.
A limited data of different households with different setups is provided on a csv file for the system to calculate the savings.

Preperation for the application.
As the application is activated two items need to be prepared:
- Instantiate the declared object “xList”.
- Indicate the starting time and date of the application as part of the status
bar.
Define a local function that will extract required information from the CSV File :ExtractFieldFromLine(AnsiString snglLine, int fieldNr, char delim)
Program the OnTimer event so that the image imgGreen is randomly repositioned on the same height but can take any position from left to right
inside the forms visible space.
Add code to the OnClick-event of the button [Load Power consumption data]
During the loading process attend to the following:
➢ Load the data (“HOwners.csv”) into the provided TStringList object xList.
➢ Replace the delimiters with TABs.
➢ Add the updated line(s) into the provided list box.
➢ Delete the first line (meta data).

Supply code to the OnClick-event of the button [Calculate Savings[%]]
Calculate the electricity usage saved in percentages, based on a random number
calculation. According to experimental values SAVING can be achieved in the
following ranges:
Solar implications and possible savings on your electricity bill:
  Character used in 4th column Description for system Range of savings
      S Complete solar system 75% - 100%
      - No support No savings
      B Back-up solar system 20% - 40%
      W Water solar geyser 30% - 60%
Developed code must fill in column three (“Savings[%]”) by calculating a
random percentage in the indicated range.

The button [Sort acc SolarSupport + Savings] must sort your displayed data in a
special way. Add code to the OnClick-event to sort the list box data according to
the two column’s data: Solar Support and Savings[%].

Code the OnClick-event of the button [Surprise]. Your supplied
code must be able doing the following:
➢ Dynamically instantiate an image on top of the supplied panel:
    pnlSurprise. Make sure the image is fitting “inside” the panel with a border
    of 2 pixel surrounding it.
➢ Simulate a count-down from 9 to 0, indicating the relevant “digit” inside
  your image.
➢ After completion of the count-down select randomly one house-owner from
  the list box’s list and highlight it.
➢ That selected house owner will receive a surprise and need to be displayed
  on the status bar with his/ her initials, surname, and day of the week when
  he/ she was born.
      
