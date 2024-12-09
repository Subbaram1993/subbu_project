import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import sys

def send_email(project_name, build_number, build_status, build_url, changes):
    # Set your email parameters
    SENDER_EMAIL = 'ram.subaram@gmail.com'  # Replace with your email
    RECIPIENT_EMAIL = 'ram.subaram@gmail.com'  # Replace with the recipient email
    SMTP_SERVER = 'smtp.gmail.com'  # Use your SMTP server (e.g., Gmail)
    SMTP_PORT = 587  # Port for TLS

    # Create the email content
    subject = f"Build {project_name} - Build #{build_number} - {build_status}"
    body = f"""
    Build Information:
    - Status: {build_status}
    - Project: {project_name}
    - Build URL: {build_url}
    - Changes: {changes}
    """

    # Create MIME message
    msg = MIMEMultipart()
    msg['From'] = SENDER_EMAIL
    msg['To'] = RECIPIENT_EMAIL
    msg['Subject'] = subject
    msg.attach(MIMEText(body, 'plain'))

    try:
        # Set up the SMTP server and send the email
        with smtplib.SMTP(SMTP_SERVER, SMTP_PORT) as server:
            server.starttls()  # Secure the connection
            server.login(SENDER_EMAIL, 'your_email_password')  # Provide your email password or app password
            server.sendmail(SENDER_EMAIL, RECIPIENT_EMAIL, msg.as_string())
            print("Email sent successfully")
    except Exception as e:
        print(f"Error sending email: {e}")
        sys.exit(1)

if __name__ == "__main__":
    project_name = sys.argv[1]
    build_number = sys.argv[2]
    build_status = sys.argv[3]
    build_url = sys.argv[4]
    changes = sys.argv[5]

    send_email(project_name, build_number, build_status, build_url, changes)
