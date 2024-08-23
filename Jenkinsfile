pipeline {
    agent any

    tools {
        nodejs 'Node.js' {
            installDir 'C:/Program Files/Jenkins/tools/nodejs'
            version 'v14.17.0'
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
