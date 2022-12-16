#include <iostream>
using namespace std;
int main()
{
  																				// Message
  int mSize;
  int message[255];
  cout << "Enter the message Size please-> ";
  cin >> mSize;
  cout << "Enter  the message please-> ";
  for (int i = 0; i < mSize; i++)
    cin >> message[i];
  																				// Generator
  int gSize;
  int generator[64];
  cout << "Enter  the generator Size please-> ";
  cin >> gSize;
  cout << "Enter the generator please-> ";
  for (int i = 0; i < gSize; i++)
    cin >> generator[i];

  if (!(generator[0] == 1 &&
        generator[gSize - 1] == 1))
  {
    cerr << "\nERROR: MSB and LSB of the Generator must be 1\n";
    return -1;
  }

  cout << "\nSENDER\n======\n";
  cout << "Message is : ";
  for (int i = 0; i < mSize; i++)
    cout << message[i];
  cout << endl<<endl;
  cout << "Generator is-> ";
  for (int i = 0; i < gSize; i++)
    cout << generator[i];
  cout << endl<<endl;

  																					// Message + r 0's
  int codeword[mSize + (gSize - 1)];
  for (int i = 0; i < mSize; i++)
    codeword[i] = message[i];
  for (int i = mSize; i < mSize + (gSize - 1); i++)
    codeword[i] = 0;

  																					// Binary Division
  int temp[mSize + (gSize - 1)];
  for (int i = 0; i < mSize + (gSize - 1); i++)
    temp[i] = codeword[i];
  for (int i = 0; i < mSize; i++)
  {
    int j = 0, k = i;
    if (temp[k] >= generator[j])
      while (j < gSize)
        temp[k++] ^= generator[j++];
  }

  																					// CRC
  int crc[64];
  for (int i = 0, j = mSize; i < (gSize - 1); i++, j++)
    crc[i] = temp[j];

  cout << "CRC: ";
  for (int i = 0; i < (gSize - 1); i++)
    cout << crc[i];
  cout << endl<<endl;

  																					// Codeword + CRC
  for (int i = 0, j = mSize; i < (gSize - 1); i++, j++)
    codeword[j] = crc[i];

  cout << "Transmition Codeword is -> ";
  for (int i = 0; i < mSize + (gSize - 1); i++)
    cout << codeword[i];
  cout << endl<<endl;

  cout << "\nNOISY CHANNEL SIMULATION\n========================\n";
  int nb, n;
  cout << "Enter Number of Bits to Flip please: ";
  cin >> nb;
  if (nb > 0 && nb < mSize + (gSize - 1))
  {
    if (nb == 0)
      cout << "Codeword Not Changed.\n";
    for (int i = 0; i < nb; i++)
    {
      cout << "Enter Bit Position to be Fliped-> ";
      cin >> n;
      if (n > 0 && n < mSize + (gSize - 1))
        codeword[n - 1] = codeword[n - 1] == 0 ? 1 : 0;
      else
        cout << "Invalid Position. Codeword Not Changed.\n";
    }
  }
  else
    cout << "Invalid Request. Codeword Not Changed.\n";

  cout << "\nRECEIVER\n========\n";
  cout << "Received Codeword is-> ";
  for (int i = 0; i < mSize + (gSize - 1); i++)
    cout << codeword[i];
  cout << endl<<endl;
  																					// Binary Division
  int temp2[mSize + (gSize - 1)];
  for (int i = 0; i < mSize + (gSize - 1); i++)
    temp2[i] = codeword[i];
  for (int i = 0; i < mSize; i++)
  {
    int j = 0, k = i;
    if (temp2[k] >= generator[j])
      while (j < gSize)
        temp2[k++] ^= generator[j++];
  }

  																					// Remainder
  int rem[64];
  for (int i = mSize, j = 0; i < mSize + (gSize - 1); i++, j++)
    rem[j] = temp2[i];

  cout << "Remainder: ";
  for (int i = 0; i < (gSize - 1); i++)
    cout << rem[i];
  cout << endl<<endl;
 																					// Checking Error
  int flag = false;
  for (int i = 0; i < (gSize - 1); i++)
    if (rem[i] != 0)
      flag = true;
 																					 // Declare Result
  cout << endl;
  if (!flag)
    cout << "TRANSMISSION OK!" << endl;
  else
    cout << "TRANSMISSION ERROR DETECTED!" << endl;

  return 0;
}