pipeline {
    agent any

    tools {
        nodejs 'Node.js' {
            installDir 'C:\\Program Files\\Jenkins\\tools\\\"C:\\Program Files\\nodejs\\node.exe\"'
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
