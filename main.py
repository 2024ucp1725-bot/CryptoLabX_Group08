from pathlib import Path
from datetime import datetime


BASE_DIR = Path(__file__).resolve().parent
DATASET_DIR = BASE_DIR / "datasets"
LOG_FILE = BASE_DIR / "outputs" / "cryptolabx.log"


def log_action(option):
    LOG_FILE.parent.mkdir(parents=True, exist_ok=True)

    with open(LOG_FILE, "a", encoding="utf-8") as file:
        current_time = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
        file.write(f"{current_time} - Selected option: {option}\n")


def analyze_file():
    files = list(DATASET_DIR.glob("*.txt"))

    if not files:
        print("\nNo text files found in datasets folder.")
        return

    file_path = files[0]

    with open(file_path, "r", encoding="utf-8") as file:
        text = file.read()

    characters = len(text)
    words = len(text.split())
    lines = len(text.splitlines())

    letters = sum(1 for char in text if char.isalpha())

    frequency = {}

    for char in text.lower():
        if char.isalpha():
            frequency[char] = frequency.get(char, 0) + 1

    print("\n========== File Analysis ==========")
    print("File:", file_path.name)
    print("Characters:", characters)
    print("Words:", words)
    print("Lines:", lines)
    print("Letters:", letters)

    print("\nLetter Frequency:")

    for letter in sorted(frequency):
        print(f"{letter}: {frequency[letter]}")

    print("===================================\n")


def show_menu():
    while True:
        print("\n=================================")
        print("        CryptoLabX Toolkit")
        print("=================================")
        print("1. Encrypt")
        print("2. Decrypt")
        print("3. Attack")
        print("4. Analyze")
        print("5. Exit")
        print("=================================")

        choice = input("Enter your choice: ")

        if choice == "1":
            log_action("Encrypt")
            print("\nEncrypt module: Coming Soon")

        elif choice == "2":
            log_action("Decrypt")
            print("\nDecrypt module: Coming Soon")

        elif choice == "3":
            log_action("Attack")
            print("\nAttack module: Coming Soon")

        elif choice == "4":
            log_action("Analyze")
            analyze_file()

        elif choice == "5":
            log_action("Exit")
            print("\nExiting CryptoLabX...")
            break

        else:
            log_action("Invalid option")
            print("\nInvalid choice. Please select 1-5.")


if __name__ == "__main__":
    show_menu()
