pipeline {
    agent any

    tools {
        nodejs 'Node.js v20.17.0'
    }

    stages {
        stage('Build') {
            steps {
                sh 'npm run build'
            }
        }
    }
}
