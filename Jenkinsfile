pipeline {
    agent any

    tools {
        nodejs 'Node.js' {
            installDir 'C:/Program Files/Jenkins/tools/nodejs'
            version 'v20.17.0'
        }
    }

    stages {
        stage('Build') {
            steps {
                sh 'npm run build'
            }
        }
    }
}
