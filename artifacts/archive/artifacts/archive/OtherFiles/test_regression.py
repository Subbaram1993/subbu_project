import os
import subprocess

# Define the regression test suite
test_suite = [
    'test_regression_1.py',
    'test_regression_2.py',
    'test_regression_3.py'
]

# Define the command to run the regression tests
test_command = 'python -m unittest discover -v -p'

# Define the directory where the test results will be stored
test_results_dir = 'test_results'

# Create the test results directory if it doesn't exist
if not os.path.exists(test_results_dir):
    os.makedirs(test_results_dir)

# Run the regression tests
for test in test_suite:
    test_file = os.path.join(test_results_dir, test)
    with open(test_file, 'w') as f:
        subprocess.run([test_command, test], stdout=f, stderr=f)

# Create a tarball of the test results
tarball_name = 'regression-test-results.tar.gz'
tarball_path = os.path.join(test_results_dir, tarball_name)
subprocess.run(['tar', '-czf', tarball_path, test_results_dir])

# Upload the tarball to GitHub Releases
import requests
github_token = os.environ['GITHUB_TOKEN']
github_repo = 'Subbaram1993/subbu_project'
github_release = 'Regression Build'
github_asset_name = tarball_name
github_asset_path = tarball_path

headers = {
    'Authorization': f'token {github_token}',
    'Content-Type': 'application/octet-stream'
}

response = requests.post(
    f'https://api.github.com/repos/{github_repo}/releases',
    headers=headers,
    json={
        'tag_name': github_release,
        'target_commitish': 'main',
        'name': github_release,
        'body': 'Automatically generated regression build'
    }
)

if response.status_code == 201:
    release_id = response.json()['id']
    response = requests.post(
        f'https://api.github.com/repos/{github_repo}/releases/{release_id}/assets',
        headers=headers,
        json={
            'name': github_asset_name,
            'download_count': 0
        }
    )

    if response.status_code == 201:
        asset_id = response.json()['id']
        with open(github_asset_path, 'rb') as f:
            response = requests.put(
                f'https://api.github.com/repos/{github_repo}/releases/{release_id}/assets/{asset_id}',
                headers=headers,
                data=f.read()
            )

        if response.status_code == 200:
            print(f'Regression build uploaded to GitHub Releases: {github_release}')
        else:
            print(f'Error uploading regression build to GitHub Releases: {response.text}')
    else:
        print(f'Error creating release asset: {response.text}')
else:
    print(f'Error creating release: {response.text}')
