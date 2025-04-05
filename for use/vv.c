#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a valid RGB color (format: R,G,B)
int is_valid_rgb(const char *str) {
    int r, g, b;
    return (sscanf(str, "%d,%d,%d", &r, &g, &b) == 3 && 
            r >= 0 && r <= 255 && 
            g >= 0 && g <= 255 && 
            b >= 0 && b <= 255);
}

// Function to check if a string is a valid XPM file path
int is_valid_asset_path(const char *str) {
    size_t len = strlen(str);
    return (len > 4 && strcmp(str + len - 4, ".xpm") == 0);
}

// Function to check if a line represents part of the map
int is_map_line(const char *line) {
    int has_valid_char = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        char c = line[i];
        // Map can contain these specific characters
        if (c == '0' || c == '1' || c == 'N' || c == 'S' || 
            c == 'E' || c == 'W' || c == 'A') {
            has_valid_char = 1;
        } else if (!isspace(c)) {
            return 0; // Invalid character found
        }
    }
    return has_valid_char;
}

// Main validation function
void validate_config(FILE *file) {
    char line[256];
    int has_no = 0, has_so = 0, has_we = 0, has_ea = 0, has_f = 0, has_c = 0;
    int in_map = 0;

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }
        
        // Skip empty lines
        if (len == 0) continue;
        
        // Check for texture and color configurations
        char identifier[3];
        char value[240];
        
        if (sscanf(line, "%2s %239s", identifier, value) == 2) {
            if (strcmp(identifier, "NO") == 0 && is_valid_asset_path(value)) {
                has_no = 1;
            } else if (strcmp(identifier, "SO") == 0 && is_valid_asset_path(value)) {
                has_so = 1;
            } else if (strcmp(identifier, "WE") == 0 && is_valid_asset_path(value)) {
                has_we = 1;
            } else if (strcmp(identifier, "EA") == 0 && is_valid_asset_path(value)) {
                has_ea = 1;
            } else if (strcmp(identifier, "F") == 0 && is_valid_rgb(value)) {
                has_f = 1;
            } else if (strcmp(identifier, "C") == 0 && is_valid_rgb(value)) {
                has_c = 1;
            }
        } else if (is_map_line(line)) {
            // We've found a map line
            if (!in_map) {
                // First map line encountered
                in_map = 1;
                
                // Check if all required configurations are present
                if (has_no && has_so && has_we && has_ea && has_f && has_c) {
                    printf("OK\n");
                } else {
                    printf("Error: Missing required configurations\n");
                }
            }
        }
    }
    
    if (!in_map) {
        printf("Error: No map found\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }
    
    validate_config(file);
    fclose(file);
    
    return 0;
}
