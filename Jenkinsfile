pipeline {
    agent any

    tools {
        nodejs 'Node.js'
    }

    stages {
        stage('Build') {
            steps {
                sh 'npm run build'
            }
        }
    }
}
