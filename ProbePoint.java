//Test your implementation by generating 1 million random points against which to probe and 1000 randomly generated probe points.

import java.util.*;

public class ProbePoint 
{

	public static void main(String[] args) 
	{
		int NUM_POINTS = 1000000;
		int numRand = 0;
		int databaseArray[][] = new int[NUM_POINTS][3];
		int probeArray[] = new int[3];
		int result0 = 0, result1 = 0, result2 = 0, resultSumTemp = 0, resultSum = 0, nearest = 0;
		
		Random rand = new Random();
		
		
		for (int i = 0; i < NUM_POINTS; i++)
		{
			numRand = rand.nextInt(1000) + 1;
			databaseArray[i][0] = numRand;

			numRand = rand.nextInt(1000) + 1;
			databaseArray[i][1] = numRand;

			numRand = rand.nextInt(1000) + 1;
			databaseArray[i][2] = numRand;
		}
		for (int i = 0; i < 1000; i++)
		{
			numRand = rand.nextInt(1000) + 1;
			probeArray[0] = numRand;

			numRand = rand.nextInt(1000) + 1;
			probeArray[1] = numRand;

			numRand = rand.nextInt(1000) + 1;
			probeArray[2] = numRand;

			for (int j = 0; j < NUM_POINTS; j++)
			{
				result0 = Math.abs(probeArray[0] - databaseArray[j][0]);
				result1 = Math.abs(probeArray[1] - databaseArray[j][1]);
				result2 = Math.abs(probeArray[2] - databaseArray[j][2]);
				resultSumTemp = result0 + result1 + result2;
				if (j == 0)
				{
					resultSum = resultSumTemp;
					nearest = j;
				}
				else if (resultSumTemp < resultSum)
				{
					resultSum = resultSumTemp;
					nearest = j;
				}
			}

			System.out.println("*--------------------*");
			System.out.println("Probe Point: " + probeArray[0] + "/" + probeArray[1] + "/" + probeArray[2]);
			System.out.println("Nearest Point: " + databaseArray[nearest][0] + "/" + databaseArray[nearest][1] + "/" + databaseArray[nearest][2]);
			System.out.println("*--------------------*");
		}
	}
}