import requests
import json
import time

# URL of the API
url = "https://obs.itu.edu.tr/api/ders-kayit/v21"

# JSON body
data = {
    "ECRN": ["10587", "10603"],
    "SCRN": []
}

# Headers including the Bearer token for authorization
headers = {
    "Authorization": "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1bmlxdWVfbmFtZSI6Iml0dVxcc2FjYWsyMSIsImRpc3BsYXlfbmFtZSI6IkVuZXMgIFNhw6dhayIsInNlc3Npb24iOiI1ZjA2MTU4OS1iZjdjLTQ5YWQtYWQ3OS0wYWYwMTRhM2YyMmMiLCJyb2xlIjpbImxpc2FucyIsIm9ncmVuY2kiXSwiaWRlbnRpdHkiOiIxNTAyMTAwMTQiLCJuYmYiOjE3MjY4MjI3ODcsImV4cCI6MTcyNjg0NDIyOSwiaWF0IjoxNzI2ODIyNzg3fQ.RdWt9IRI4E_jN8njCg9ZpvU2e1Z8FICvbQb1rkJ9FnA",
    "Content-Type": "application/json"
}

# Function to send the POST request
def send_post_request():
    response = requests.post(url, headers=headers, data=json.dumps(data))

    return response

# Loop to send the request every 3 seconds
while True:
    response = send_post_request()
    print(f"Status Code: {response.status_code}, Response: {response.text}")
    time.sleep(3)  # Wait for 3 seconds before the next request
