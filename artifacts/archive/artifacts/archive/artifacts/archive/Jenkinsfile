import groovy.json.JsonSlurper

pipeline {
    agent any

    parameters {
        string(name: 'CUSTOM_PARAM', defaultValue: 'default-value', description: 'Custom parameter for the build')
        string(name: 'BUILD_NUMBER', defaultValue: '01', description: 'Build number')
        string(name: 'JOB_NAME', defaultValue: 'subbu_project', description: 'Job name from the commit message or JSON file')
    }

    stages {
        stage('Read JSON Config') {
            steps {
                script {
                    // Default job name to the parameter value
                    def jobName = params.JOB_NAME

                    if (fileExists('config.json')) {
                        def jsonFile = readFile('config.json')
                        def json
			try{
                            json = new JsonSlurper().parseText(jsonFile)
                        } catch (Exception e) {
                            echo "Error parsing JSON: ${e.message}"
                            currentBuild.result = 'FAILURE'
                            error "Failed to parse config.json"
                        }

                        def jsonJobName = json?.buildConfig?.jobName

                        if (jsonJobName) {
                            echo "Job Name from JSON: ${jsonJobName}"
                            jobName = jsonJobName
                        } else {
                            echo "Warning: 'jobName' not found in config.json"
                        }
                    } else {
                        echo "Warning: config.json file not found"
                    }

                    // Extract activity from commit message if available
                    def commitMessage = sh(script: 'git log -1 --pretty=%B', returnStdout: true).trim()
                    def activity = commitMessage.tokenize().find { it.startsWith('activity:') }
                    
                    if (activity) {
                        jobName = activity.replace('activity:', '').trim()
                        echo "Job Name derived from commit message activity: ${jobName}"
                    } else {
                        echo "Using job name from parameter or JSON: ${jobName}"
                    }

                    env.JOB_NAME = jobName
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    def customParam = params.CUSTOM_PARAM
                    def buildNumber = params.BUILD_NUMBER
                    def jobName = env.JOB_NAME

                    echo "Custom Parameter: ${customParam}"
                    echo "Build Number: ${buildNumber}"
                    echo "Job Name: ${jobName}"

                    // Example usage in a script
                    sh """
                    echo "Building with custom parameter: ${customParam}"
                    echo "Build Number: ${buildNumber}"
                    echo "Job Name: ${jobName}"
                    # Add your build commands here
                    """
                }
            }
        }
    }

    post {
        success {
            echo 'Build successful!'
            // Any additional actions on success
        }
        failure {
            echo 'Build failed!'
            // Any additional actions on failure
        }
    }
}
