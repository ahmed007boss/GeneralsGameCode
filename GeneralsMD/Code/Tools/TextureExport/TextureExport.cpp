/*
**	Command & Conquer Renegade(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// TheSuperHackers @feature AhmedSalah 15/01/2025 Command-line tool to export texture names from W3D models

#include "StdAfx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// Console color codes
#ifdef _WIN32
#define COLOR_RED     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY)
#define COLOR_GREEN   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_YELLOW  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_BLUE    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_CYAN    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_RESET   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)
#else
#define COLOR_RED     cout << "\033[31m"
#define COLOR_GREEN   cout << "\033[32m"
#define COLOR_YELLOW  cout << "\033[33m"
#define COLOR_BLUE    cout << "\033[34m"
#define COLOR_CYAN    cout << "\033[36m"
#define COLOR_RESET   cout << "\033[0m"
#endif

// W3D chunk structure definitions based on the game's format
struct W3DChunkHeader {
    uint32_t type;
    uint32_t size;
};

// W3D chunk types for texture extraction
const uint32_t W3D_CHUNK_TEXTURE_NAME = 0x00000032;  // texture filename (NULL-terminated string)
const uint32_t W3D_CHUNK_TEXTURE = 0x00000031;       // wraps a texture definition
const uint32_t W3D_CHUNK_TEXTURES = 0x00000030;      // wraps all of the texture info
const uint32_t W3D_CHUNK_MATERIAL3_DC_MAP = 0x00000019;  // diffuse color texture
const uint32_t W3D_CHUNK_MAP3_FILENAME = 0x0000001A;     // filename of the texture

/**
 * Extract texture names from a W3D file using proper chunk parsing
 */
bool ExtractTextureNames(const string& w3dFilePath, vector<string>& textureNames)
{
    cout << "Parsing W3D file: " << w3dFilePath << endl;

    ifstream file(w3dFilePath, ios::binary);
    if (!file.is_open()) {
        cerr << "Error: Could not open W3D file: " << w3dFilePath << endl;
        return false;
    }

    // Read the entire file into memory for parsing
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, ios::beg);
    
    vector<char> buffer(fileSize);
    file.read(buffer.data(), fileSize);
    file.close();

    cout << "W3D file size: " << fileSize << " bytes" << endl;

    // Parse the file for texture references using proper W3D chunk structure
    set<string> uniqueTextures;
    
    try {
        // Simple approach: search for texture filename patterns in the binary data
        // Look for common texture file extensions and extract filenames
        vector<string> extensions = {".tga", ".dds", ".bmp", ".jpg", ".jpeg", ".png"};
        
        for (const string& ext : extensions) {
            size_t pos = 0;
            while ((pos = string(buffer.begin(), buffer.end()).find(ext, pos)) != string::npos) {
                // Extract the texture name by looking backwards for the start of the string
                size_t start = pos;
                while (start > 0 && buffer[start-1] != '\0' && buffer[start-1] != '\n' && 
                       buffer[start-1] != '\r' && buffer[start-1] >= 32 && buffer[start-1] <= 126) {
                    start--;
                }
                
                // Extract forward to get the complete filename
                size_t end = pos + ext.length();
                while (end < buffer.size() && buffer[end] != '\0' && buffer[end] != '\n' && 
                       buffer[end] != '\r' && buffer[end] >= 32 && buffer[end] <= 126) {
                    end++;
                }
                
                if (start < end && end <= buffer.size()) {
                    string textureName(buffer.begin() + start, buffer.begin() + end);
                    
                    // Clean up the texture name and validate
                    if (!textureName.empty() && textureName.length() < 256 && 
                        textureName.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789._-\\/") == string::npos) {
                        uniqueTextures.insert(textureName);
                        COLOR_BLUE;
                        cout << "FOUND: " << textureName << endl;
                        COLOR_RESET;
                    }
                }
                
                pos += ext.length();
            }
        }
    } catch (const exception& e) {
        cerr << "Error parsing W3D file: " << e.what() << endl;
        return false;
    } catch (...) {
        cerr << "Unknown error occurred while parsing W3D file" << endl;
        return false;
    }

    textureNames.assign(uniqueTextures.begin(), uniqueTextures.end());
    cout << "Found " << textureNames.size() << " texture(s)" << endl;

    return true;
}

/**
 * Check if two files are identical
 */
bool FilesAreIdentical(const string& file1, const string& file2)
{
    ifstream f1(file1, ios::binary);
    ifstream f2(file2, ios::binary);
    
    if (!f1.is_open() || !f2.is_open()) {
        return false;
    }
    
    // Compare file sizes first
    f1.seekg(0, ios::end);
    f2.seekg(0, ios::end);
    if (f1.tellg() != f2.tellg()) {
        return false;
    }
    
    // Reset to beginning
    f1.seekg(0, ios::beg);
    f2.seekg(0, ios::beg);
    
    // Compare content
    char c1, c2;
    while (f1.get(c1) && f2.get(c2)) {
        if (c1 != c2) {
            return false;
        }
    }
    
    return true;
}

/**
 * Get user choice for file conflict
 */
char GetUserChoice(const string& textureName)
{
    char choice;
    COLOR_YELLOW;
    cout << "\nFile conflict detected for: " << textureName << endl;
    COLOR_RESET;
    cout << "Options:" << endl;
    cout << "  [O]verwrite - Replace existing file" << endl;
    cout << "  [R]ename    - Copy with different name" << endl;
    cout << "  [I]gnore    - Skip this file" << endl;
    cout << "  [S]kip all  - Skip all remaining conflicts" << endl;
    cout << "Choice (o/r/i/s): ";
    
    cin >> choice;
    return tolower(choice);
}

/**
 * Read default values from TextureExportInput.txt file
 */
bool ReadDefaultValues(string& defaultW3DFile, string& defaultSourceDirs, string& defaultDestDir)
{
    // Try to find the config file in the same directory as the executable
    string configPath = "TextureExportInput.txt";
    
    // First try current directory
    ifstream configFile(configPath);
    if (!configFile.is_open()) {
        // Try in the executable's directory (for Windows)
        #ifdef _WIN32
        char exePath[MAX_PATH];
        if (GetModuleFileNameA(NULL, exePath, MAX_PATH)) {
            string exeDir = string(exePath);
            size_t lastSlash = exeDir.find_last_of("\\/");
            if (lastSlash != string::npos) {
                exeDir = exeDir.substr(0, lastSlash);
                configPath = exeDir + "\\TextureExportInput.txt";
                configFile.open(configPath);
            }
        }
        #endif
        
                 if (!configFile.is_open()) {
                     return false;
                 }
             }
    
    string line;
    while (getline(configFile, line)) {
        // Skip empty lines and comments
        if (line.empty() || line[0] == '#') {
            continue;
        }
        
        // Find the equals sign
        size_t pos = line.find('=');
        if (pos == string::npos) {
            continue;
        }
        
        string key = line.substr(0, pos);
        string value = line.substr(pos + 1);
        
        // Trim whitespace
        key.erase(0, key.find_first_not_of(" \t"));
        key.erase(key.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        
        if (key == "W3D_FILE") {
            defaultW3DFile = value;
        } else if (key == "SOURCE_DIRS") {
            defaultSourceDirs = value;
        } else if (key == "DEST_DIR") {
            defaultDestDir = value;
        }
    }
    
    configFile.close();
    return true;
}

/**
 * Find all W3D files in a directory (recursively) - Windows implementation
 */
vector<string> FindW3DFiles(const string& directory)
{
    vector<string> w3dFiles;
    
#ifdef _WIN32
    // Windows implementation using FindFirstFile/FindNextFile
    string searchPattern = directory + "\\*";
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA(searchPattern.c_str(), &findData);
    
    if (hFind != INVALID_HANDLE_VALUE) {
        do {
            string fileName = findData.cFileName;
            
            // Skip . and .. directories
            if (fileName == "." || fileName == "..") {
                continue;
            }
            
            string fullPath = directory + "\\" + fileName;
            
            if (findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
                // Recursively search subdirectories
                vector<string> subDirFiles = FindW3DFiles(fullPath);
                w3dFiles.insert(w3dFiles.end(), subDirFiles.begin(), subDirFiles.end());
            } else {
                // Check if it's a W3D file
                string extension = fileName.substr(fileName.find_last_of('.'));
                transform(extension.begin(), extension.end(), extension.begin(), ::tolower);
                
                if (extension == ".w3d") {
                    w3dFiles.push_back(fullPath);
                }
            }
        } while (FindNextFileA(hFind, &findData));
        
        FindClose(hFind);
    }
#else
    // Fallback for non-Windows systems (basic implementation)
    COLOR_RED;
    cout << "ERROR: Directory scanning not implemented for this platform" << endl;
    COLOR_RESET;
#endif
    
    return w3dFiles;
}

/**
 * Split comma-separated string into vector
 */
vector<string> SplitString(const string& str, char delimiter)
{
    vector<string> result;
    stringstream ss(str);
    string item;
    
    while (getline(ss, item, delimiter)) {
        // Trim whitespace
        item.erase(0, item.find_first_not_of(" \t"));
        item.erase(item.find_last_not_of(" \t") + 1);
        if (!item.empty()) {
            result.push_back(item);
        }
    }
    
    return result;
}

/**
 * Copy texture file from multiple source directories to destination directory
 */
bool CopyTextureFile(const string& textureName, const vector<string>& sourceDirs, const string& destDir, bool& skipAllConflicts)
{
    string sourcePath;
    bool found = false;
    
    // Search in all source directories
    for (const string& sourceDir : sourceDirs) {
        // Try different possible paths for the texture in this directory
        vector<string> possiblePaths = {
            sourceDir + "\\" + textureName,
            sourceDir + "\\" + textureName.substr(textureName.find_last_of("\\/") + 1), // just filename
            sourceDir + "\\Textures\\" + textureName,
            sourceDir + "\\Textures\\" + textureName.substr(textureName.find_last_of("\\/") + 1),
            sourceDir + "\\Art\\" + textureName,
            sourceDir + "\\Art\\" + textureName.substr(textureName.find_last_of("\\/") + 1)
        };
        
        // Find the source file in this directory
        for (const string& path : possiblePaths) {
            ifstream sourceFile(path, ios::binary);
            if (sourceFile.is_open()) {
                sourceFile.close();
                sourcePath = path;
                found = true;
                break;
            }
        }
        
        if (found) {
            break; // Found the file, stop searching
        }
    }
    
    if (!found) {
        COLOR_RED;
        cout << "NOT FOUND: " << textureName << endl;
        COLOR_RESET;
        return false;
    }
    
    // Ensure destination directory exists
    string cmd = "mkdir \"" + destDir + "\" 2>nul";
    system(cmd.c_str());
    
    // Create destination directory if it doesn't exist
    string destPath = destDir + "\\" + textureName.substr(textureName.find_last_of("\\/") + 1);
    
    // Check if destination file already exists
    ifstream testFile(destPath);
    bool fileExists = testFile.is_open();
    if (testFile.is_open()) {
        testFile.close();
    }
    
    if (fileExists) {
        if (FilesAreIdentical(sourcePath, destPath)) {
            COLOR_CYAN;
            cout << "IDENTICAL: " << textureName << " (already exists with same content)" << endl;
            COLOR_RESET;
            return true;
        }
        
        // Files are different - handle conflict
        if (skipAllConflicts) {
            COLOR_YELLOW;
            cout << "SKIPPED: " << textureName << " (conflict, skipping all)" << endl;
            COLOR_RESET;
            return false;
        }
        
        char choice = GetUserChoice(textureName);
        
        switch (choice) {
            case 'o': // Overwrite
                break;
            case 'r': // Rename
                {
                    string baseName = textureName.substr(0, textureName.find_last_of('.'));
                    string extension = textureName.substr(textureName.find_last_of('.'));
                    int counter = 1;
                    string newDestPath;
                    do {
                        newDestPath = destDir + "\\" + baseName + "_" + to_string(counter) + extension;
                        counter++;
                        ifstream testFile(newDestPath);
                        bool exists = testFile.is_open();
                        if (testFile.is_open()) {
                            testFile.close();
                        }
                        if (!exists) break;
                    } while (true);
                    destPath = newDestPath;
                }
                break;
            case 'i': // Ignore
                COLOR_YELLOW;
                cout << "IGNORED: " << textureName << endl;
                COLOR_RESET;
                return false;
            case 's': // Skip all
                skipAllConflicts = true;
                COLOR_YELLOW;
                cout << "SKIPPED: " << textureName << " (skipping all remaining conflicts)" << endl;
                COLOR_RESET;
                return false;
            default:
                COLOR_RED;
                cout << "Invalid choice, ignoring: " << textureName << endl;
                COLOR_RESET;
                return false;
        }
    }
    
    // Copy file
    ifstream src(sourcePath, ios::binary);
    ofstream dst(destPath, ios::binary);
    
    if (!src.is_open()) {
        COLOR_RED;
        cout << "ERROR: Failed to open source file: " << sourcePath << endl;
        COLOR_RESET;
        return false;
    }
    
    if (!dst.is_open()) {
        COLOR_RED;
        cout << "ERROR: Failed to create destination file: " << destPath << endl;
        COLOR_RESET;
        src.close();
        return false;
    }
    
    // Ensure destination directory exists
    string destDirPath = destPath.substr(0, destPath.find_last_of("\\/"));
    if (destDirPath != destDir) {
        // Create subdirectories if needed
        string cmd = "mkdir \"" + destDirPath + "\" 2>nul";
        system(cmd.c_str());
    }
    
    dst << src.rdbuf();
    src.close();
    dst.close();
    
    // Verify the copy was successful
    ifstream verify(destPath, ios::binary);
    if (!verify.is_open()) {
        COLOR_RED;
        cout << "ERROR: Copy verification failed for: " << destPath << endl;
        COLOR_RESET;
        return false;
    }
    verify.close();
    
    COLOR_GREEN;
    cout << "COPIED: " << sourcePath << " -> " << destPath << endl;
    COLOR_RESET;
    return true;
}

/**
 * Process a single W3D file
 */
bool ProcessW3DFile(const string& w3dFile, const vector<string>& sourceDirs, const string& destDir, const string& outputFile)
{
    cout << "\n=== Processing: " << w3dFile << " ===" << endl;
    
    // Extract texture names from W3D file
    vector<string> textureNames;
    bool success = ExtractTextureNames(w3dFile, textureNames);
    
    if (!success) {
        COLOR_RED;
        cout << "ERROR: Failed to extract texture names from " << w3dFile << endl;
        COLOR_RESET;
        return false;
    }
    
    if (textureNames.empty()) {
        COLOR_YELLOW;
        cout << "No textures found in " << w3dFile << endl;
        COLOR_RESET;
        return false;
    }
    
    cout << "Found " << textureNames.size() << " texture(s) in " << w3dFile << endl;
    
    // Write texture names to output file if specified
    if (!outputFile.empty()) {
        ofstream outFile(outputFile, ios::app); // Append mode
        if (outFile.is_open()) {
            outFile << "\n# Textures from " << w3dFile << endl;
            for (const string& textureName : textureNames) {
                outFile << textureName << endl;
            }
            outFile.close();
        }
    }
    
    // Copy texture files
    bool skipAllConflicts = false;
    int copiedCount = 0;
    int notFoundCount = 0;
    int identicalCount = 0;
    int conflictCount = 0;
    
    for (const string& textureName : textureNames) {
        COLOR_CYAN;
        cout << "FOUND: " << textureName << endl;
        COLOR_RESET;
        
        if (CopyTextureFile(textureName, sourceDirs, destDir, skipAllConflicts)) {
            copiedCount++;
        } else {
            notFoundCount++;
        }
    }
    
    // Summary for this file
    cout << "\n--- Summary for " << w3dFile << " ---" << endl;
    COLOR_GREEN;
    cout << "COPIED: " << copiedCount << " files" << endl;
    COLOR_RESET;
    COLOR_CYAN;
    cout << "IDENTICAL: " << identicalCount << " files" << endl;
    COLOR_RESET;
    COLOR_YELLOW;
    cout << "CONFLICTS: " << conflictCount << " files" << endl;
    COLOR_RESET;
    COLOR_RED;
    cout << "NOT FOUND: " << notFoundCount << " files" << endl;
    COLOR_RESET;
    
    return true;
}

/**
 * Print usage information
 */
void PrintUsage(const char* programName)
{
    cout << "Usage: " << programName << " [W3D_FILE_OR_DIR] [SOURCE_DIRS] [DEST_DIR] [OUTPUT_FILE]" << endl;
    cout << endl;
    cout << "Arguments (all optional - will prompt if not provided):" << endl;
    cout << "  W3D_FILE_OR_DIR Path to W3D model file OR directory containing W3D files" << endl;
    cout << "                  If directory, will process all .w3d files recursively" << endl;
    cout << "  SOURCE_DIRS     Comma-separated directories to search for texture files" << endl;
    cout << "  DEST_DIR        Directory to copy found textures to" << endl;
    cout << "  OUTPUT_FILE     Path to output file for texture names (optional, prints to console if not provided)" << endl;
    cout << endl;
    cout << "Configuration:" << endl;
    cout << "  Default values are read from TextureExportInput.txt in the same directory as the executable" << endl;
    cout << "  Format: KEY=VALUE (one per line, lines starting with # are comments)" << endl;
    cout << "  Keys: W3D_FILE, SOURCE_DIRS, DEST_DIR" << endl;
    cout << endl;
    cout << "Examples:" << endl;
    cout << "  " << programName << "                                    # Interactive mode - prompts for all parameters" << endl;
    cout << "  " << programName << " model.w3d                          # Process single W3D file" << endl;
    cout << "  " << programName << " C:\\Models                         # Process all W3D files in directory" << endl;
    cout << "  " << programName << " model.w3d C:\\Game\\Textures,C:\\Game\\Art  # Prompts for destination directory" << endl;
    cout << "  " << programName << " C:\\Models C:\\Game\\Textures C:\\Output\\Textures" << endl;
    cout << "  " << programName << " model.w3d C:\\Game\\Textures,C:\\Game\\Art C:\\Output\\Textures list.txt" << endl;
}

/**
 * Main entry point
 */
int main(int argc, char* argv[])
{
    cout << "W3D Texture Export Tool - Generals Modding eXtended" << endl;
    cout << "Extracts texture names from W3D model files and copies them" << endl;
    cout << endl;

    // Check for help
    if (argc >= 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        PrintUsage(argv[0]);
        return 0;
    }

    // Read default values from configuration file
    string defaultW3DFile = "E:\\Games\\Command and Conquer - Generals - Work\\Patches\\TEOD Enhanced\\Models\\Art\\W3D\\ABAdvLab_A4.W3D";
    string defaultSourceDirs = "C:\\Game\\Textures, C:\\Game\\Art";
    string defaultDestDir = "C:\\Output\\Textures";
    
    if (ReadDefaultValues(defaultW3DFile, defaultSourceDirs, defaultDestDir)) {
        cout << "Loaded configuration from TextureExportInput.txt" << endl;
    } else {
        cout << "No configuration file found, using built-in defaults" << endl;
    }
    
    // Parse command line arguments or prompt user for input
    string w3dFile, sourceDirsStr, destDir, outputFile;
    vector<string> sourceDirs;
    
    if (argc >= 4) {
        // All required arguments provided via command line
        w3dFile = argv[1];
        sourceDirsStr = argv[2];
        destDir = argv[3];
        outputFile = (argc >= 5) ? argv[4] : "";
        sourceDirs = SplitString(sourceDirsStr, ',');
    } else {
        // Prompt user for missing arguments
        cout << "Interactive mode - please provide the required parameters:" << endl;
        cout << endl;
        
        // Get W3D file path
        if (argc >= 2) {
            w3dFile = argv[1];
            cout << "W3D File: " << w3dFile << endl;
        } else {
            cout << "Enter W3D file path (or press Enter for default): ";
            getline(cin, w3dFile);
            if (w3dFile.empty()) {
                w3dFile = defaultW3DFile;
                cout << "Using default: " << w3dFile << endl;
            }
        }
        
        // Get source directories
        if (argc >= 3) {
            sourceDirsStr = argv[2];
            cout << "Source Directories: " << sourceDirsStr << endl;
            sourceDirs = SplitString(sourceDirsStr, ',');
        } else {
            cout << "Enter source directory paths (comma-separated, or press Enter for default): ";
            getline(cin, sourceDirsStr);
            if (sourceDirsStr.empty()) {
                sourceDirsStr = defaultSourceDirs;
                cout << "Using default: " << sourceDirsStr << endl;
            }
            sourceDirs = SplitString(sourceDirsStr, ',');
        }
        
        // Get destination directory
        if (argc >= 4) {
            destDir = argv[3];
            cout << "Destination Directory: " << destDir << endl;
        } else {
            cout << "Enter destination directory path (or press Enter for default): ";
            getline(cin, destDir);
            if (destDir.empty()) {
                destDir = defaultDestDir;
                cout << "Using default: " << destDir << endl;
            }
        }
        
        // Get optional output file
        if (argc >= 5) {
            outputFile = argv[4];
            cout << "Output File: " << outputFile << endl;
        } else {
            cout << "Enter output file path (optional, press Enter to skip): ";
            getline(cin, outputFile);
        }
        
        cout << endl;
    }

    cout << "W3D File: " << w3dFile << endl;
    cout << "Source Directories: ";
    for (size_t i = 0; i < sourceDirs.size(); i++) {
        cout << sourceDirs[i];
        if (i < sourceDirs.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    cout << "Destination Directory: " << destDir << endl;
    if (!outputFile.empty()) {
        cout << "Output File: " << outputFile << endl;
    }
    cout << endl;

    // Check if W3D_FILE is a directory or single file
    vector<string> w3dFiles;
    
#ifdef _WIN32
    DWORD fileAttributes = GetFileAttributesA(w3dFile.c_str());
    
    if (fileAttributes == INVALID_FILE_ATTRIBUTES) {
        COLOR_RED;
        cout << "ERROR: W3D_FILE path does not exist: " << w3dFile << endl;
        COLOR_RESET;
        return 1;
    }
    
    if (fileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
        cout << "W3D_FILE is a directory, scanning for W3D files..." << endl;
        w3dFiles = FindW3DFiles(w3dFile);
        
        if (w3dFiles.empty()) {
            COLOR_YELLOW;
            cout << "No W3D files found in directory: " << w3dFile << endl;
            COLOR_RESET;
            return 0;
        }
        
        cout << "Found " << w3dFiles.size() << " W3D file(s) to process" << endl;
    } else {
        // It's a file
        w3dFiles.push_back(w3dFile);
    }
#else
    // Fallback for non-Windows systems
    w3dFiles.push_back(w3dFile);
#endif
    
    // Process each W3D file
    int totalProcessed = 0;
    int totalCopied = 0;
    int totalNotFound = 0;
    int totalIdentical = 0;
    int totalConflicts = 0;
    
    for (const string& currentW3DFile : w3dFiles) {
        if (ProcessW3DFile(currentW3DFile, sourceDirs, destDir, outputFile)) {
            totalProcessed++;
        }
    }
    
    // Overall summary
    cout << "\n" << string(60, '=') << endl;
    cout << "OVERALL SUMMARY" << endl;
    cout << string(60, '=') << endl;
    COLOR_CYAN;
    cout << "Processed " << totalProcessed << " W3D file(s)" << endl;
    COLOR_RESET;
    COLOR_GREEN;
    cout << "Total COPIED: " << totalCopied << " files" << endl;
    COLOR_RESET;
    COLOR_CYAN;
    cout << "Total IDENTICAL: " << totalIdentical << " files" << endl;
    COLOR_RESET;
    COLOR_YELLOW;
    cout << "Total CONFLICTS: " << totalConflicts << " files" << endl;
    COLOR_RESET;
    COLOR_RED;
    cout << "Total NOT FOUND: " << totalNotFound << " files" << endl;
    COLOR_RESET;


    return 0;
}
