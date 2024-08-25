import groovy.json.JsonSlurper

pipeline {
    agent any

    parameters {
        string(name: 'CUSTOM_PARAM', defaultValue: 'default-value', description: 'Custom parameter for the build')
        string(name: 'BUILD_NUMBER', defaultValue: '01', description: 'Build number')
        string(name: 'JOB_NAME', defaultValue: 'default-job-name', description: 'Job name from the JSON file or commit message')
    }

    stages {
        stage('Read JSON Config') {
            steps {
                script {
                    if (fileExists('config.json')) {
                        def jsonFile = readFile('config.json')
                        def json = new JsonSlurper().parseText(jsonFile)
                        def jobName = json.buildConfig.jobName

                        if (jobName) {
                            echo "Job Name from JSON: ${jobName}"
                            env.JOB_NAME = jobName
                        } else {
                            echo "Error: 'jobName' not found in config.json"
                            currentBuild.result = 'FAILURE'
                            error "Job name not found in config.json"
                        }
                    } else {
                        echo "config.json file not found"
                        currentBuild.result = 'FAILURE'
                        error "config.json file not found"
                    }
                }
            }
        }

        stage('Build') {
            steps {
                script {
                    def customParam = params.CUSTOM_PARAM
                    def buildNumber = params.BUILD_NUMBER
                    def jobName = params.JOB_NAME

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