import groovy.json.JsonSlurper

pipeline {
    agent any

    parameters {
        string(name: 'CUSTOM_PARAM', defaultValue: 'default-value', description: 'Custom parameter for the build')
        string(name: 'BUILD_NUMBER', defaultValue: '01', description: 'Build number')
    }

    stages {
        stage('Read JSON Config') {
            steps {
                script {
                    def jsonFile = readFile('config.json')
                    def json = new JsonSlurper().parseText(jsonFile)
                    def jobName = json.buildConfig.jobName

                    echo "Job Name from JSON: ${jobName}"

                    // Pass the job name as a parameter if needed
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
}
